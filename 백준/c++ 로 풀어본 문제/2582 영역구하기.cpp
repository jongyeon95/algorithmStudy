#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int arr[101][101];
int visited[101][101];
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
int areaCount=0;
vector<int> areaSize;
int m,n,k; // m세로 n 가로 

void bfs(int x, int y){
	queue<pair<int,int>> q;
	q.push({x,y});
	while(!q.empty()){
		pair<int,int> p;
		p=q.front();
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int tx=p.first+dx[i];
			int ty=p.second+dy[i];
			if(tx<0||tx>=m||ty<0||ty>=n)
				continue;
			if(arr[tx][ty]==0){
				arr[tx][ty]=areaCount;
				areaSize[areaCount-1]++;
				q.push({tx,ty});
			}
		}

	}
}


int main(){
	cin.tie(0);
	cout.sync_with_stdio(false);
	cin >> m  >>  n >> k;
	memset(arr,0,sizeof(arr));
	memset(visited,false,sizeof(visited));
	int x1,x2,y1,y2;
	for (int i = 0; i < k; ++i)
	{
		cin >>y1>>x1>>y2>>x2;
		for (int i = x1; i <x2 ; ++i)
		{
			for (int j = y1; j <y2; ++j)
			{
				arr[i][j]=-1;
			}
		}
	}

	for(int i=0; i<m; i++){
		for (int j = 0; j < n; ++j)
		{
			if(arr[i][j]==0){
				areaCount++;
				areaSize.push_back(1);
				arr[i][j]=areaCount;
				bfs(i,j);		
			}
		}
	}
	sort(areaSize.begin(),areaSize.end());
	cout<<areaCount<<"\n";
	for (int i = 0; i < areaSize.size(); ++i)
	{
		cout << areaSize[i] << " ";
	}




}