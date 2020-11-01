#include <iostream>
#include <string>
#include <deque>
#include <queue>
using namespace std;
struct Player
{
	int y;
	int x;
	
};

int dy[]={1,1,1,0,0,0,-1,-1,-1};
int dx[]={-1,0,1,0,-1,1,-1,0,1};



int main(){
	int answer=0;
	deque<string> dq;

	for (int i = 0; i < 8; ++i)
	{
		string s;
		cin >> s;
		dq.push_back(s);
	}
	string line="........";



	queue<Player> q;
	q.push({7,0});
	bool check=false;
	while(!q.empty()&&!check){
		
		int size=q.size();
		for(int i=0; i<size; i++){
			Player temp=q.front();
			q.pop();
			if(dq[temp.y][temp.x]=='#')
				continue;
			for(int j=0; j<9; j++){
				int ty=temp.y+dy[j];
				int tx=temp.x+dx[j];
				if(ty<0||tx<0||ty>7||tx>7||dq[ty][tx]=='#'){
					continue;
				}
				if(ty==0&&tx==7){
					check=true;
					answer=1;
					break;
				}
				q.push({ty,tx});
			}
			if(check)
				break;

		}
		dq.pop_back();
		dq.push_front(line);

	}
	cout<<answer;



}