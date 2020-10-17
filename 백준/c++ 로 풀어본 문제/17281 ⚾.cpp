#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int n;
vector<vector<int>> inning;
vector<int> players;
bool checked[9];
int answer=0;

void input(){
	cin >> n;
	inning.resize(n);
	memset(checked,false,sizeof(checked));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			int temp;
			cin>>temp;
			inning[i].push_back(temp);
		}
	}

}

void playGame(){
	
	int outCnt=0;
	int score=0;
	int flag=0;
	for (int i = 0; i < n; ++i)
	{
		queue<int> ground;
		for (int j = 0; j < 3; ++j)	
			ground.push(0);
		outCnt=0;
		
		while(outCnt<3){
			int command=inning[i][players[flag]];
			flag++;
			if(flag==9)
				flag=0;

			if(command==0){
				outCnt++;
				if(outCnt==3)
					break;
			}
			else{
				for (int j = 0; j < command; ++j)
				{
					if(j==0)
						ground.push(1);
					else{
						ground.push(0);
					}
					score+=ground.front();
					ground.pop();
				}
			}
		}
		
	}
	if(answer<score)
		answer=score;

}



void dfs(int cnt){
	if(cnt==9){
		playGame();
		return;
	}
	if(cnt==3){
		players.push_back(0);
		dfs(cnt+1);
		players.pop_back();
		return;
	}




	for(int i=1; i<9; i++){
		if(!checked[i]){
			checked[i]=true;
			players.push_back(i);
			dfs(cnt+1);
			players.pop_back();
			checked[i]=false;
		}
	}
}

int main(){
	input();
	dfs(0);
	cout<<answer;
}