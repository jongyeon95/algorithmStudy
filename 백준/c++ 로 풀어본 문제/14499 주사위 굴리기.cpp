#include <iostream>
#include <algorithm>
using namespace std;
int dice[]={0,0,0,0,0,0};
int map[20][20];
int N,M;
int diceY,diceX;
int dx[]={0,1,-1,0,0};
int dy[]={0,0,0,-1,1};

void move(int dir){
	if(dir==1){
		int cDice[]={dice[0],dice[4],dice[2],dice[5],dice[3],dice[1]};
		copy(cDice,cDice+6,dice);
	}
	else if(dir==2){
		int cDice[]={dice[0],dice[5],dice[2],dice[4],dice[1],dice[3]};
		copy(cDice,cDice+6,dice);
	}
	else if(dir==3){
		int cDice[]={dice[1],dice[2],dice[3],dice[0],dice[4],dice[5]};
		copy(cDice,cDice+6,dice);
	}
	else if(dir==4){
		int cDice[]={dice[3],dice[0],dice[1],dice[2],dice[4],dice[5]};
		copy(cDice,cDice+6,dice);
	}
}

int main(){
	int k;
	cin >> N >> M >> diceY >> diceX >> k;
	int command[k];
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			cin >> map[i][j];
	for(int i=0; i<k; i++)
		cin >> command[i];
	for (int i = 0; i < k; ++i)
	{
		int tx=diceX+dx[command[i]];
		int ty=diceY+dy[command[i]];
		if(ty<0||tx<0||ty>=N||tx>=M)
			continue;
		move(command[i]);
		diceY=ty;
		diceX=tx;
		if(map[ty][tx]==0){
			map[ty][tx]=dice[3];
		}
		else{
			dice[3]=map[ty][tx];
			map[ty][tx]=0;
		}
		cout << dice[1] << endl;
	}
	return 0;

}