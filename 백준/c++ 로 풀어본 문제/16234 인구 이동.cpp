#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int N,L,R;//L 이상 R 이하
int map[50][50];
int temp[50][50];
bool visited[50][50];
int dy[]={0,1,0,-1};
int dx[]={1,0,-1,0};
int cnt;


bool bfs(int y, int x){

	queue<pair<int,int>> q; // 탐색을 위한 큐
	queue<pair<int,int>> tempq; // 바뀔 위치 넣을 큐
	
	q.push({y,x});
	bool check=false; //인구이동 체크
	int sum=map[y][x];
	int count=1;
	tempq.push({y,x});
	
	while(!q.empty()){
		pair<int, int> p=q.front();
		q.pop();
		for(int i=0; i<4; i++){
			int ty=p.first+dy[i];
			int tx=p.second+dx[i];
			
			if(ty<0||tx<0||ty>=N||tx>=N||visited[ty][tx])
				continue;
			
			int absNum=abs(map[ty][tx]-map[p.first][p.second]);
			
			if(absNum>=L&&absNum<=R){
				tempq.push({ty,tx});
				sum+=map[ty][tx];
				visited[ty][tx]=true;
				q.push({ty,tx});
				check=true;
				count++;
			}
		}
	}

	sum/=count;

	while(!tempq.empty()){ // 인구이동 일어난 곳만 치환
		pair<int, int> p=tempq.front();
		tempq.pop();
		temp[p.first][p.second]=sum;
	}

	return check;
}


int main(){
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


	cin >> N >> L >> R;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin >> map[i][j];
		}
	}

	bool check=true;
	cnt=0;

	while(check){
		check=false;
		memset(visited,false,sizeof(visited));
		memset(temp,0,sizeof(temp));
		
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				if(!visited[i][j]){
					visited[i][j]=true;
					if(bfs(i,j)){//인구이동 했으면 true
						check=true;
					}
				}
			}
		}

		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				if(temp[i][j]!=0)// 바뀐 거만 치환
					map[i][j]=temp[i][j];
			}
		}

		cnt++;
	}
	cout << cnt-1;

}