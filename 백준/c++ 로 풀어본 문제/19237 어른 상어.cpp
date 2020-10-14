#include <iostream>
#include <vector>
using namespace std;
//위 아래 왼쪽 위
int dy[]={0,-1,1,0,0};
int dx[]={0,0,0,-1,1};
int n,m,k;
int deadCount;


struct Shark
{
	int index;
	int y;
	int x;
	int dir;
	int dirArr[5][5];
	bool alive;
};

pair<int,int> smell[20][20];
int map[20][20];

vector<Shark> sharks;

void input(){
	cin >> n >> m >> k;
	sharks.resize(m+1);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> map[i][j];
			if(map[i][j]!=0){
				sharks[map[i][j]].index=map[i][j];
				sharks[map[i][j]].y=i;
				sharks[map[i][j]].x=j;
				sharks[map[i][j]].alive=true;
			}
			smell[i][j]={0,0};
		}
	}

	for(int i=1; i<=m; i++){
		cin >> sharks[i].dir;
	}
	for (int i = 1; i <= m; ++i)
	{
		for(int j=1; j<=4; j++){
			for(int k=1; k<=4; k++){
				cin>>sharks[i].dirArr[j][k];
			}
		}
	}
}

void spread(){
	for (int i = 1; i <= m; ++i)
	{
		if(sharks[i].alive){
			smell[sharks[i].y][sharks[i].x]={sharks[i].index,k};
		}
	}
}

void move(){
	for (int i = 1; i <=m; ++i)
	{
		if(!sharks[i].alive)
			continue;

		bool noSmell=false;
		for (int j = 1; j <= 4; ++j)
		{
			int ty=sharks[i].y+dy[sharks[i].dirArr[sharks[i].dir][j]];
			int tx=sharks[i].x+dx[sharks[i].dirArr[sharks[i].dir][j]];
			if(ty<0||tx<0||ty>=n||tx>=n)
				continue;
			if(smell[ty][tx].first==0){
				noSmell=true;
				if(map[ty][tx]!=0){
					sharks[i].alive=false;
					map[sharks[i].y][sharks[i].x]=0;
					deadCount--;
					break;
				}
				else{
					map[sharks[i].y][sharks[i].x]=0;
					map[ty][tx]=i;
					sharks[i].y=ty;
					sharks[i].x=tx;
					sharks[i].dir=sharks[i].dirArr[sharks[i].dir][j];
					break;
				}
			}
		}

		if(!noSmell){
			for (int j = 1; j <= 4; ++j){
				int ty=sharks[i].y+dy[sharks[i].dirArr[sharks[i].dir][j]];
				int tx=sharks[i].x+dx[sharks[i].dirArr[sharks[i].dir][j]];
				if(ty<0||tx<0||ty>=n||tx>=n)
					continue;
				if(smell[ty][tx].first==i){
					map[sharks[i].y][sharks[i].x]=0;
					map[ty][tx]=i;
					sharks[i].y=ty;
					sharks[i].x=tx;
					sharks[i].dir=sharks[i].dirArr[sharks[i].dir][j];
					break;
					
				}
			}

		}
		
	}
}

void timeUp(){
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if(smell[i][j].first!=0){
				smell[i][j].second--;
				if(smell[i][j].second==0){
					smell[i][j].first=0;
				}
			}
		}
		
	}
}




int main(){
	input();
	int cnt=0;
	deadCount=m;
	while(cnt<=1000){
		if(deadCount==1)
			break;
		spread();
		move();
		timeUp();
		cnt++;
	}
	if(cnt>1000)
		cnt=-1;
	cout <<cnt;
	
	
}