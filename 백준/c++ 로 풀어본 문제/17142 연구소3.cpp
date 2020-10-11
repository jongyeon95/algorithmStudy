#include <iostream>
#include <vector>
#include <queue>
using namespace std;


struct virus
{
	int y;
	int x;
	
};

vector<virus> v;
vector<virus> selected;
int map[50][50];
int n,m;
int answer;
int zeroNumber=0;
int dy[]={0,0,1,-1};
int dx[]={1,-1,0,0};

void input(){
	cin >> n >> m;
	for(int i=0; i<n; i++){
		for (int j = 0; j < n; ++j)
		{
			cin >> map[i][j];
			if(map[i][j]==2){
				v.push_back({i,j});
			}
			if(map[i][j]==0)
				zeroNumber++;
		}
	}
	answer=987654321;
}



bool checkVirus(int tempMap[50][50]){
	
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if(tempMap[i][j]==0)
				return false;
		}
	}
	return true;
}

void solved(){

	int tempMap[50][50];
	int cnt=0;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
				tempMap[i][j]=map[i][j];
		}
	}

	queue<virus> q;
	for (int i = 0; i < selected.size(); ++i)
	{
		q.push(selected[i]);
	}
	int count=zeroNumber;
	
	while(!q.empty()){
		int size=q.size();
		if(count==0){
				if(answer>cnt)
					answer=cnt;
				break;

		}
		cnt++;
		while(size--){
			virus temp= q.front();
			q.pop();
			for (int i = 0; i < 4; ++i)
			{
				int ty=temp.y+dy[i];
				int tx=temp.x+dx[i];
				if(ty<0||tx<0||ty>=n||tx>=n){
						continue;
				}
				if(tempMap[ty][tx]==0||tempMap[ty][tx]==2){
					if(tempMap[ty][tx]==0){
						count--;
					}
					tempMap[ty][tx]=3;
					q.push({ty,tx});
				}
			}
		}
	}
	


}

void selectArea(int flag, int cnt){
	if(cnt==m){
		solved();
		return;
	}


	for(int i=flag; i<v.size(); i++){
		selected.push_back(v[i]);
		selectArea(i+1,cnt+1);
		selected.pop_back();
	}
}


int main(){
	input();
	selectArea(0,0);
	if(answer==987654321)
		answer=-1;
	cout<<answer;
}