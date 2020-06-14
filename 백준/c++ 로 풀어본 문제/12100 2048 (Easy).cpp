#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int map[20][20];
int cMap[20][20];
int mapSize;
int ans=0;
vector<int> command;

void input(){
	cin >> mapSize;
	for (int i = 0; i < mapSize; ++i)
		for (int j = 0; j < mapSize; ++j)
			cin >> map[i][j];
}

//맵 복사
void copy(){
	for (int i = 0; i < mapSize; ++i)
		for (int j = 0; j < mapSize; ++j)
			cMap[i][j]=map[i][j];
}

// 움직이기
// 상하좌우방향에 맞추어 맵에서 0인 아닌 값을  Queue에 넣는다.
// 해당 맵의 위치는 0으로 바꾼다.
// Queue에 값을 모두 넣었다면 상하좌우 방향에 맞추어 Queue에 있는 값을 순서대로 넣는다.
void move(int dir){
	if(dir==0){//상
		for (int j = 0; j < mapSize; ++j)
		{
			queue<int> q;
			for (int i = 0; i < mapSize; ++i)
			{
				if(cMap[i][j]!=0){
					q.push(cMap[i][j]);
					cMap[i][j]=0;
				}
			}
			int size=q.size();
			for (int i = 0; i < size; ++i)
			{
				cMap[i][j]=q.front();
				q.pop();
			}
		}
	}
	else if(dir==1){//우
		for (int i = 0; i < mapSize; ++i)
		{
			queue<int> q;
			for (int j = mapSize-1; j >= 0; j--)
			{
				if(cMap[i][j]!=0){
					q.push(cMap[i][j]);
					cMap[i][j]=0;
				}
			}
			int size=q.size();
			for (int j = mapSize-1; j >= mapSize-size; j--)
			{
				cMap[i][j]=q.front();
				q.pop();
			}
		}

	}
	else if(dir==2){//하
		for (int j = 0; j < mapSize; ++j)
		{
			queue<int> q;
			for (int i = mapSize-1; i >= 0; i--)
			{
				if(cMap[i][j]!=0){
					q.push(cMap[i][j]);
					cMap[i][j]=0;
				}
			}
			int size=q.size();
			for (int i = mapSize-1; i >= mapSize-size; i--)
			{
				cMap[i][j]=q.front();
				q.pop();
			}
		}
		
	}
	else if(dir==3){//좌 
		for (int i = 0; i < mapSize; ++i)
		{
			queue<int> q;
			for (int j = 0; j < mapSize; j++)
			{
				if(cMap[i][j]!=0){
					q.push(cMap[i][j]);
					cMap[i][j]=0;
				}
			}
			int size=q.size();
			for (int j = 0; j < size; j++)
			{
				cMap[i][j]=q.front();
				q.pop();
			}
		}
		
	}
}

// 이웃한 값의 숫자가 같다면 순서가 빠른 위치를 2배하고 느린 위치를 0으로 바꾼다.
void sumNum(int dir){
	if(dir==0){// 상
		for (int j = 0; j < mapSize; ++j)
		{
			for (int i = 0; i < mapSize-2; ++i)
			{
				if( cMap[i][j]!=0 && (cMap[i+1][j] == cMap[i][j]) ){
					cMap[i][j]*=2;
					cMap[i+1][j]=0;
				}
			}
		}
	}
	else if(dir==1){// 우 
		for (int i = 0; i < mapSize; ++i)
		{
			for (int j = mapSize-1; j >= 1; j--)
			{
				if( cMap[i][j]!=0 && (cMap[i][j-1] == cMap[i][j]) ){
					cMap[i][j]*=2;
					cMap[i][j-1]=0;
				}
			}
		}

	}
	else if(dir==2){//하
		for (int j = 0; j < mapSize; ++j)
		{
			for (int i = mapSize-1; i >= 1; i--)
			{
				if( cMap[i][j]!=0 && (cMap[i-1][j] == cMap[i][j]) ){
					cMap[i][j]*=2;
					cMap[i-1][j]=0;
				}
			}
		}
		
	}
	else if(dir==3){//좌
		for (int i = 0; i < mapSize; ++i)
		{
			for (int j = 0; j < mapSize-2; ++j)
			{
				if( cMap[i][j]!=0 && (cMap[i][j+1] == cMap[i][j]) ){
					cMap[i][j]*=2;
					cMap[i][j+1]=0;
				}
			}
		}
		
	}

}

void solve(){
	memset(cMap,0,sizeof(cMap));
	copy(); // 임시 맵 복사
	for (int i = 0; i < 5; ++i)
	{
		move(command[i]);//한 방향으로 움직인다.
		sumNum(command[i]);//합친다
		move(command[i]);//합친 후 공백을 없애기 위해 다시 움직인다. 
	}
	int result=0;
	// 합 계산
	for (int i = 0; i < mapSize; ++i)
		for (int j = 0; j < mapSize; ++j)
			if(cMap[i][j]>result)
				result=cMap[i][j];

	if(ans<result)
		ans=result;


}

// 명령의 조합 만들기
void dfs(){
	if(command.size()==5){
		solve();
		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		command.push_back(i);
		dfs();
		command.pop_back();
	}

}

int main(){
	input();
	dfs();
	cout << ans;

}