#include <iostream>
#include <cstring>
using namespace std;
int map[50][50];
int r , c , t;
int y,x;
int dy[]={0,-1,0,1};
int dx[]={1,0,-1,0};
int UpDir[]={0,1,2,3};
int DownDir[]={0,3,2,1};
int tempArr[50][50];

void input(){
	cin >> r >> c >>t;
	for (int i=0;  i<r; ++i)
	{
		for(int j=0; j<c; j++){
			cin >> map[i][j];
			if(map[i][j]==-1){
				y=i;
				x=j;
			}
		}
	}
}

void spread(){
	memset(tempArr,0,sizeof(tempArr));
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			if(map[i][j]>0){
				int cnt=0;
				for (int k = 0; k < 4; ++k)
				{
					int ty=dy[k]+i;
					int tx=dx[k]+j;
					if(ty<0||tx<0||ty>=r||tx>=c||map[ty][tx]==-1){
						continue;
					}
					tempArr[ty][tx]+=map[i][j]/5;
					cnt++;
				}
				tempArr[i][j]+=map[i][j]-(map[i][j]/5)*cnt;
			}
		}
	}
	tempArr[y][x]=-1;
	tempArr[y-1][x]=-1;
}

void move(){

	///top
	int flag=0;
	int PreNum=0;
	int PostNum=0;
	int Y=y-1;
	int X=x;
	while(1){
		int ty=Y+dy[UpDir[flag]];
		int tx=X+dx[UpDir[flag]];
		if(ty<0||tx<0||ty>=r||tx>=c){
			flag++;
			continue;
		}
		if(tempArr[ty][tx]==-1){
			break;
		}
		PostNum=tempArr[ty][tx];
		tempArr[ty][tx]=PreNum;
		PreNum=PostNum;
		Y=ty;
		X=tx;

	}
	flag=0;
	PreNum=0;
	PostNum=0;
	Y=y;
	X=x;
	while(1){
		int ty=Y+dy[DownDir[flag]];
		int tx=X+dx[DownDir[flag]];
		if(ty<0||tx<0||ty>=r||tx>=c){
			flag++;
			continue;
		}
		if(tempArr[ty][tx]==-1){
			break;
		}
		PostNum=tempArr[ty][tx];
		tempArr[ty][tx]=PreNum;
		PreNum=PostNum;
		Y=ty;
		X=tx;
	}
	
}

void copyMap(){
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			map[i][j]=tempArr[i][j];
		}
	}
}


int main(){
	input();
	while(t--){
		spread();
		move();
		copyMap();
		
	}
	int answer=0;
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)	
			answer+=map[i][j];
		
		
	cout<<answer+2;

}