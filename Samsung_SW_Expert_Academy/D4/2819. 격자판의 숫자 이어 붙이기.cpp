#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
char map[4][4];
bool check[10000000];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
vector<string> v;
int result=0;


struct xy
{
	int y;
	int x;
	string s;
};

void bfs(int y, int x){
	queue<xy> q;
	string t="";
	q.push({y,x,t+map[y][x]});
	while(!q.empty()){
		xy temp=q.front();
		q.pop();
		if(temp.s.size()==7){
			int tempNum=1;
			int checkNum=0;
			for (int i = 6; i >=0; i--)
			{
				checkNum+=(temp.s[i]-'0')*tempNum;
				tempNum*=10;
			}
			if(!check[checkNum]){
				check[checkNum]=true;
				result++;
			}
			continue;
		}
		for (int i = 0; i < 4; ++i)
		{
			int ty=temp.y+dy[i];
			int tx=temp.x+dx[i];
			if(ty<0||tx<0||ty>3||tx>3)
				continue;
			q.push({ty,tx,temp.s+map[ty][tx]});
			
		}
	}

}


int main(){
	cin.tie(0);
	cout.sync_with_stdio(false);
	int testcase;
	cin >> testcase;
	for (int t = 1; t <= testcase; ++t){
		result=0;
		memset(check,false,sizeof(check));
		for (int i = 0; i < 4; ++i)
			for (int j = 0; j < 4; ++j){
				cin >> map[i][j];
			}
		for (int i = 0; i < 4; ++i)
			for (int j = 0; j < 4; ++j)
				bfs(i,j);
		cout <<"#"<<t<<" "<< result <<"\n";
		
	}

}