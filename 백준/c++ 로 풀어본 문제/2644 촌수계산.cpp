#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool visited[101];

vector<vector<int>> v;


int bfs(int start, int end){

	queue<pair<int,int>> q;
	q.push({start,0});
	while(!q.empty()){
		pair<int,int> p=q.front();
		q.pop();
		for(int i=0; i<v[p.first].size(); i++){
			if(v[p.first][i]==end)
				return p.second+1;
			if(!visited[v[p.first][i]]){
				visited[v[p.first][i]]=true;
				q.push({v[p.first][i],p.second+1});
			}
		}
	
	}

	return -1;

}


int main(){
	int n,m;
	int start,end;
	cin >> n;
	cin >> start >> end;
	cin >> m;
	int a,b;
	v.resize(n+1);
	
	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	cout<<bfs(start,end);



}