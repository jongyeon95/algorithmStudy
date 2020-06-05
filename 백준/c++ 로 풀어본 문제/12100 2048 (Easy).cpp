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

void copy(){
	for (int i = 0; i < mapSize; ++i)
		for (int j = 0; j < mapSize; ++j)
			cMap[i][j]=map[i][j];
}

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
	copy();
	for (int i = 0; i < 5; ++i)
	{
		move(command[i]);
		sumNum(command[i]);
		move(command[i]);
	}
	int result=0;
	for (int i = 0; i < mapSize; ++i)
		for (int j = 0; j < mapSize; ++j)
			if(cMap[i][j]>result)
				result=cMap[i][j];
	if(ans<result)
		ans=result;


}


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