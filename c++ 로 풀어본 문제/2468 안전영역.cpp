#include <iostream>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;

int map[101][101];
int dx[]={-1,1,0,0};
int dy[]={0,0,1,-1};
bool visited[101][101];
int n;
void initVisited(){
	memset(visited,false,sizeof(visited));
}

struct xy
{
	int x;
	int y;
};

int Bfs(int hegiht){
	initVisited();
	int returnArea=0;

	for(int i=0; i<n; i++){
		for(int j=0; j<n ; j++){
			if(!visited[i][j]){
				visited[i][j]=true;
				if(map[i][j]>hegiht){
					returnArea++;
					queue<xy> q;
					q.push({i,j});
					visited[i][j]=true;
					while(!q.empty()){
						xy temp=q.front();
						q.pop();
						for (int k = 0; k < 4; ++k)
						{
							int tx=temp.x+dx[k];
							int ty=temp.y+dy[k];
							if(tx>=0&&ty>=0&&tx<n&&ty<n){
								if(!visited[tx][ty]&&map[tx][ty]>hegiht){
									q.push({tx,ty});
									visited[tx][ty]=true;
								}
							}
						}
					}

				}
			}
		}
	}

	return returnArea;

}

int main(){
	
	int maxh=-1;
	int maxArea=0;
	initVisited();
	cin >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n ; j++){
			cin >> map[i][j];
			if(maxh<map[i][j])
				maxh=map[i][j];
		}
	}

	for (int i = 0; i <= maxh; ++i)
	{
		
		maxArea=max(maxArea,Bfs(i));
	}

	cout << maxArea;


}