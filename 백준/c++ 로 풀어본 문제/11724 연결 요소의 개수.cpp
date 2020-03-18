#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int n,m;
int result;
int arr[1001][1001];
bool visited[1001];

void bfs(int x){
	queue<int> q;
	for (int i = 1; i <= n; ++i)
	{
		if(arr[x][i]==1&&!visited[i]){
			q.push(i);
			visited[i]=true;
		}
	}

	while(!q.empty()){
		int temp=q.front();
		q.pop();
		for (int i = 1; i <= n; ++i)
		{
			if(arr[temp][i]==1&&!visited[i]){
			q.push(i);
			visited[i]=true;
			}
		}
	}
}


int main(){
	cin.tie(0);
	cout.sync_with_stdio(false);
	cin >> n >>m;
	result=0;

	memset(arr,0,sizeof(arr));
	memset(visited,false,sizeof(visited));
	for (int i = 0; i < m; ++i)
	{
		int x,y;
		cin >> x >> y;
		arr[x][y]=1;
		arr[y][x]=1;
	}

	for(int i=1; i<=n; i++){
		if(!visited[i]){
			visited[i]=true;
			bfs(i);
			result++;
		}
	}
	cout << result;

}