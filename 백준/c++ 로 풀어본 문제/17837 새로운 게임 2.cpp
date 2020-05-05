#include <iostream>
#include <vector>
using namespace std;
struct chess
{
	int y;
	int x;
	int dir;
};


int dx[]={0,1,-1,0,0};
int dy[]={0,0,0,-1,1};
//→, ←, ↑, ↓
int mapSize;
int chessNum;
int colorMap[13][13];
vector<int> map[13][13];
vector<chess> chessInfo;



void init(){
	cin >> mapSize >> chessNum;
	for(int i=1; i<=mapSize; i++){
		for (int j = 1; j <= mapSize; ++j)
		{
			cin >> colorMap[i][j];
		}
	}

	for (int i = 0; i < chessNum; ++i)
	{
		int y , x , dir;
		cin >> y >> x >>dir;
		chessInfo.push_back({y,x,dir});
		map[y][x].push_back(i);
	}
}

bool move(int num){
	int tdir=chessInfo[num].dir;
	int ty=chessInfo[num].y+dy[tdir];
	int tx=chessInfo[num].x+dx[tdir];
	if(ty<=0||tx<=0||ty>mapSize||tx>mapSize||colorMap[ty][tx]==2){
		if(tdir==1)
			tdir=2;
		else if(tdir==2)
			tdir=1;
		else if(tdir==3)
			tdir=4;
		else if(tdir==4)
			tdir=3;
		ty=chessInfo[num].y+dy[tdir];
		tx=chessInfo[num].x+dx[tdir];
		chessInfo[num].dir=tdir;
		if(ty<=0||tx<=0||ty>mapSize||tx>mapSize||colorMap[ty][tx]==2){
			return false;
		}
	}
	
	int py=chessInfo[num].y;
	int px=chessInfo[num].x;
	int flag=0;
	for (int i = 0; i < map[py][px].size(); ++i)
	{
		if( map[py][px][i]==num){
			flag=i;
			break;
		}
	}

	if(colorMap[ty][tx]==0){
		int Tempsize=map[py][px].size();
		for(int i=flag; i<Tempsize; i++){
			int temp=map[py][px][i];
			chessInfo[temp].y=ty;
			chessInfo[temp].x=tx;
			map[ty][tx].push_back(temp);
		}
		for(int i=flag; i<Tempsize; i++){
			map[py][px].pop_back();
		}
	}
	else if(colorMap[ty][tx]==1){
		int Tempsize=map[py][px].size();
		for(int i=Tempsize-1; i>=flag; i--){
			int temp=map[py][px][i];
			chessInfo[temp].y=ty;
			chessInfo[temp].x=tx;
			map[ty][tx].push_back(temp);
		}
		for(int i=flag; i<Tempsize; i++){
			map[py][px].pop_back();
		}
	}

	if(map[ty][tx].size()>=4){
		return true;
	}
	else
		return false;
}


void solve(){
	int cnt=0;
	while(1){
		cnt++;
		for (int i = 0; i < chessNum; ++i)
		{
			if(move(i)){
				cout<<cnt;
				return;
			}
		}
		
		if(cnt>1000){
				cout << -1;
				return;
		}
	}

}

int main(){
	init();
	solve();
}