#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <string>
using namespace std;
vector<string> v;
int n;
bool visited[100][100];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

void RgbBfs(char c,int y,int x){
	queue<pair<int,int>> q;
	q.push({y,x});
	while(!q.empty()){
		pair<int , int> temp=q.front();
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int tx=temp.second+dx[i];
			int ty=temp.first+dy[i];
			if(tx<0||ty<0||tx>=n||ty>=n)
				continue;
			if(!visited[ty][tx]&&v[ty][tx]==c){
				visited[ty][tx]=true;
				q.push({ty,tx});
			}
		}
	}
}


void RbBfs(char c,int y,int x){
	char tchar=c;
	if(c=='R')
		tchar='G';
	if(c=='G')
		tchar='R';
	queue<pair<int,int>> q;
	q.push({y,x});
	while(!q.empty()){
		pair<int , int> temp=q.front();
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int tx=temp.second+dx[i];
			int ty=temp.first+dy[i];
			if(tx<0||ty<0||tx>=n||ty>=n)
				continue;
			if(!visited[ty][tx]&&(v[ty][tx]==c||v[ty][tx]==tchar)){
				visited[ty][tx]=true;
				q.push({ty,tx});
			}
		}
	}
}



int main(){
	int RgbResult=0;
	int RbResult=0;
	cin >> n;
	for (int i = 0; i <n; ++i)
	{
		string s;
		cin >> s;
		v.push_back(s);
	}
	memset(visited,false,sizeof(visited));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if(!visited[i][j]){
				visited[i][j]=true;
				RgbBfs(v[i][j],i,j);
				RgbResult++;
			}
		}
	}

	memset(visited,false,sizeof(visited));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if(!visited[i][j]){
				visited[i][j]=true;
				RbBfs(v[i][j],i,j);
				RbResult++;
			}
		}
	}

	cout <<RgbResult<<" "<<RbResult;
	
}