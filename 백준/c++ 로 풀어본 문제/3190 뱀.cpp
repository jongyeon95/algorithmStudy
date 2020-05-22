#include <iostream>
#include <cstring>
#include <vector>
#include <deque>
using namespace std;
int board[101][101];// 보드 
int boardSize;// 보드 사이즈 
int apple; // 사과 수 
int command; // 뱀 방향 변환 정보
int cnt=0; // 카운트
int snakeDir=1; // 뱀 방향
int dx[]={0,1,0,-1}; // 상 우 하 좌 
int dy[]={-1,0,1,0};

deque<pair<int,int>> snake; // 뱀의 몸통 
vector<pair<int,char>> snakeMove; // 뱀이 움직이는 정보 <시간 , 방향 >


void input(){

	cin >> boardSize;
	cin >> apple;
	for (int i = 0; i < apple; ++i)
	{
		int y,x;
		cin >> y >> x;
		board[y][x]=1;
	}
	cin >> command;
	int temp=0;
	for (int i = 0; i < command; ++i)
	{
		int time;
		char dir;
		cin>> time >> dir;
		temp=time-temp;
		snakeMove.push_back({temp,dir});
		temp=time;
	}

	// 마지막 명령어 후에는 한방향으로 쭉 움직임
	snakeMove.push_back({1000,'D'});
}


void move(){
	//시작
	snake.push_back({1,1});
	board[1][1]=2;

	for (int i = 0; i <= command; ++i)
	{
		pair<int,char> temp=snakeMove[i];
		bool check=false;
		for (int j = 0; j < temp.first; j++)
		{
			int tx=snake.back().second+dx[snakeDir];
			int ty=snake.back().first+dy[snakeDir];
			// 맵을 벗어나거나  자신의 몸통에 부서지면 종료 
			if(ty<=0||tx<=0||tx>boardSize||ty>boardSize||board[ty][tx]==2){
				check=true;
				break;
			}
			// 가는곳이 사과일때 길이만 증가
			if(board[ty][tx]==1){
				snake.push_back({ty,tx});
				board[ty][tx]=2;
			}// 가는곳에 사과없을때 꽁무니는 줄어든다.
			else if(board[ty][tx]==0){
				snake.push_back({ty,tx});
				board[ty][tx]=2;
				board[snake.front().first][snake.front().second]=0;
				snake.pop_front();

			}

			cnt++;

		}
		if(check)
			break;
		// 방향 전환 
		if(temp.second=='L'){
			if(snakeDir==0)
				snakeDir=4;
			snakeDir--;
		}
		else if(temp.second=='D'){
			if(snakeDir==3)
				snakeDir=-1;
			snakeDir++;
		}

	}

}




int main(){
	memset(board,0,sizeof(board));
	input();
	move();
	cout << cnt+1;
	
}