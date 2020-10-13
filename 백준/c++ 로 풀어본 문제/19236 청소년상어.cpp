#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dy[]={-1,-1,0,1,1,1,0,-1};
int dx[]={0,-1,-1,-1,0,1,1,1};
int answer=0;

struct Fish
{
	int y;
	int x;
	int dir;
	int index;
	bool alive;
};

struct Shark
{
	int y;
	int x;
	int dir;
};

bool cmp(Fish a, Fish b){
	return a.index<b.index;
}




void solved(int Tmap[4][4],vector<Fish> fishes,Shark s,int cnt){
	int map[4][4];
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			map[i][j]=Tmap[i][j];
		}
	}


	if(cnt==0){
		fishes[map[0][0]].alive=false;
		cnt+=fishes[map[0][0]].index;
		s.dir=fishes[map[0][0]].dir;
		map[0][0]=-1;
		s.y=0;
		s.x=0;
		solved(map,fishes,s,cnt);
		return;
	}




	if(answer<cnt)
		answer=cnt;


	//move
	for (int i = 1; i < fishes.size(); ++i)
	{
		if(!fishes[i].alive)
			continue;

		for (int j = 0; j < 8; ++j)
		{
			int ty=fishes[i].y+dy[fishes[i].dir];
			int tx=fishes[i].x+dx[fishes[i].dir];
			if(ty<0||tx<0||ty>=4||tx>=4||map[ty][tx]==-1){
				fishes[i].dir++;
				if(fishes[i].dir>7)
					fishes[i].dir=0;
				continue;
			}

			if(map[ty][tx]==0){
				map[fishes[i].y][fishes[i].x]=0;
				fishes[i].y=ty;
				fishes[i].x=tx;
				map[ty][tx]=fishes[i].index;
			}
			else{
				int tempY=0;
				int tempX=0;
				int tempIndex=0;
				

				tempY=fishes[i].y;
				tempX=fishes[i].x;
				tempIndex=fishes[i].index;
				
			
				fishes[i].y=fishes[map[ty][tx]].y;
				fishes[i].x=fishes[map[ty][tx]].x;
				map[tempY][tempX]=map[ty][tx];
				
				fishes[map[ty][tx]].y=tempY;
				fishes[map[ty][tx]].x=tempX;
				map[ty][tx]=tempIndex;
				
			}
			break;
		}
	}

	



	map[s.y][s.x]=0;
	while(1){
		int ty=s.y+dy[s.dir];
		int tx=s.x+dx[s.dir];
		if(ty<0||tx<0||ty>=4||tx>=4)
			break;
		
		s.y=ty;
		s.x=tx;
		if(map[ty][tx]!=0){
			int tempNum=0;
			int tempdir=s.dir;
			tempNum=map[ty][tx];
			
			map[ty][tx]=-1;
			fishes[tempNum].alive=false;
			s.dir=fishes[tempNum].dir;			
			
			solved(map,fishes,s,cnt+fishes[tempNum].index);
			
			s.dir=tempdir;
			map[ty][tx]=tempNum;
			fishes[tempNum].alive=true;
		}
	}


}




int main(){

	vector<Fish> fishes;
	Shark s={0,0,0};
	int map[4][4];
	fishes.push_back({-1,-1,-1,-1,false});

	for (int i = 0; i < 4; ++i)
	{
		for(int j=0; j<4; j++){
			int a,b;
			cin >> a >> b;
			fishes.push_back({i,j,b-1,a,true});
			map[i][j]=a;
		}
	}
	sort(fishes.begin(), fishes.end(), cmp);
	solved(map,fishes,s,0);
	cout <<answer;

	
}