#include <iostream>
#include <cstring>
#include <string>
#include <queue>
using namespace std;

int R,C;
struct Hog
{
	int y;
	int x;
	int cnt;
};
int dy[]={0,0,1,-1};
int dx[]={1,-1,0,0};
Hog hog;
pair<int, int> biber;
char map[50][50];
bool  check[50][50];
int result;

void printMap(){
	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			cout<<map[i][j]<<" ";
		}
		cout<<endl;
	}
}

void spreadWater(){
	queue<pair<int,int>> q;
	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			if(map[i][j]=='*'){
				q.push({i,j});
			}
		}
	}
	while(!q.empty()){
		pair<int,int> p;
		p=q.front();
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int ty=dy[i]+p.first;
			int tx=dx[i]+p.second;
			if(ty<0||tx<0||ty>=R||tx>=C){
				continue;
			}
			if(map[ty][tx]=='.'){
				map[ty][tx]='*';
			}
		}
	}
}


void bfs(){
	check[hog.y][hog.x]=true;
	queue<Hog> q;
	q.push(hog);
	int count=0;
	while(!q.empty()){
		Hog temp=q.front();
		q.pop();
		if(temp.cnt>result)
			return;

		if(count==temp.cnt){
			spreadWater();
			count++;
		}
		for (int i = 0; i < 4; ++i)
		{
			int ty=dy[i]+temp.y;
			int tx=dx[i]+temp.x;
			if(ty<0||tx<0||ty>=R||tx>=C||check[ty][tx]){
				continue;
			}
			if(map[ty][tx]=='D'){

				if(temp.cnt+1<result){
					result=temp.cnt+1;
				}
				continue;
			}
			if(map[ty][tx]=='.'){
				check[ty][tx]=true;
				q.push({ty,tx,temp.cnt+1});
			}
		}
	}

}

int main(){
	result=987654321;
	memset(check,false,sizeof(check));
	cin >> R >> C;
	getchar();
	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			map[i][j]=getchar();
			if(map[i][j]=='D'){
				biber.first=i;
				biber.second=j;
			}
			if(map[i][j]=='S'){
				hog.y=i;
				hog.x=j;
				hog.cnt=0;
				map[i][j]='.';
			}

		}
		getchar();
	}
	bfs();
	if (result==987654321)
	{
		cout<<"KAKTUS";
		return 0;
	}
	cout<<result;


}