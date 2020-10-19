#include <iostream>
#include <vector>
using namespace std;
int dy[]={-1,-1,0,1,1,1,0,-1};
int dx[]={0,1,1,1,0,-1,-1,-1};
struct FireBall
{
	int y;
	int x;
	int mass;
	int speed;
	int dir;
};
int n,m,k;
vector<FireBall> balls;

void input(){
	cin >> n >> m >> k;
	for(int i=0; i<m; i++){
		int r,c,mass,s,d;
		cin >> r >> c >> mass >> s >>d;
		balls.push_back({r-1,c-1,mass,s,d}); 
	}
}

int main(){
	input();
	
	while(k-- >0){
		
		vector<FireBall> newMap[n][n];
		vector<FireBall> newBalls;
		for (int i = 0; i < balls.size(); ++i)
		{
			int ty=balls[i].y;
			int tx=balls[i].x;
			for(int j=0; j<balls[i].speed;j++){
				ty+=dy[balls[i].dir];
				if(ty<0) ty=n-1;
				if(ty>=n) ty=0;
				tx+=dx[balls[i].dir];
				if(tx<0) tx=n-1;
				if(tx>=n) tx=0;
			}
			balls[i].y=ty;
			balls[i].x=tx;
			newMap[ty][tx].push_back(balls[i]);
		}


		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(newMap[i][j].size()==1){
					newBalls.push_back(newMap[i][j][0]);
				}
				else if(newMap[i][j].size()>1){
					int totalMass=0;
					int totalSpeed=0;
					int newDir=0;
					bool check1=false;//홀수
					bool check2=false;//짝수
					for(int z=0; z<newMap[i][j].size(); z++){
						totalMass+=newMap[i][j][z].mass;
						totalSpeed+=newMap[i][j][z].speed;
						if(newMap[i][j][z].dir%2==0){
							check2=true;
						}
						else{
							check1=true;
						}
					}
					if(check1&&check2)
						newDir=1;
					totalMass/=5;
					if(totalMass==0)
						continue;
					totalSpeed/=newMap[i][j].size();
					for(int z=0; z<4; z++){
						newBalls.push_back({i,j,totalMass,totalSpeed,z*2+newDir});
					}


				}
			}
			
		}
		balls.clear();
		balls=newBalls;
				

	}
	int answer=0;
	for (int i = 0; i < balls.size(); ++i)
	{
		answer+=balls[i].mass;
	}
	cout<<answer;

}