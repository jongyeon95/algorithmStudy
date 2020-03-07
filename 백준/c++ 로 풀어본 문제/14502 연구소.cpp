#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int map[8][8];
int tempMap[8][8];
int temptempMap[8][8];
int n,m;
int result=0;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

void inputMap(){
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> map[i][j];
		}
	}

}

void spreadVirus(){
	queue<pair<int,int>> q;
	for (int i = 0; i <n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if(tempMap[i][j]==2)
				q.push({i,j});
		}
	}
	memcpy(temptempMap,tempMap,sizeof(tempMap));

	while(!q.empty()){
		pair<int,int> temp;
		temp=q.front();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int tx=dx[i]+temp.first;
			int ty=dy[i]+temp.second;

			if(tx<0||ty<0||tx>=n||ty>=m)
				continue;
			if(temptempMap[tx][ty]==0){
				temptempMap[tx][ty]=2;
				q.push({tx,ty});
			}
		}
	}

}

int findSafeAreaSize(){
	int tempResult=0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if(temptempMap[i][j]==0)
				tempResult++;
		}
	}
	return tempResult;

}



void makeWall(int wallCount){

	if(wallCount==3){
		int compareResult;
		spreadVirus();
		compareResult=findSafeAreaSize();
		if(result<compareResult)
			result=compareResult;
		return;
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if(tempMap[i][j]==0){
				tempMap[i][j]=1;
				wallCount++;
				makeWall(wallCount);
				wallCount--;
				tempMap[i][j]=0;
			}
		}	
	}

}

int main(){
	
	inputMap();
	memcpy(tempMap,map,sizeof(map));
	makeWall(0);
	cout << result;


	

}