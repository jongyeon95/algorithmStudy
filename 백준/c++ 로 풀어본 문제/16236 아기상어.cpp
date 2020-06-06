#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
struct Shark
{
	int y;
	int x;
	int size;
	int hungry;
	int cnt;
};
Shark shark;
int map[20][20];
int N;
int dy[]={0,0,1,-1};
int dx[]={1,-1,0,0};


void input(){
	cin >> N;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j){
			cin >> map[i][j];
			if(map[i][j]==9){
				shark.y=i;
				shark.x=j;
				shark.size=2;
				shark.hungry=0;
				shark.cnt=0;
				map[i][j]=0;
			}
		}
}

void eat(Shark temp , int cnt){
	shark.y=temp.y;
	shark.x=temp.x;
	if(shark.hungry+1==shark.size){
		shark.size++;
		shark.hungry=0;
	}
	else
		shark.hungry++;
	shark.cnt+=cnt;
	map[temp.y][temp.x]=0;

}

bool findFood(){

	queue<Shark> q;
	q.push(shark);
	bool visit[N][N];
	memset(visit,false,sizeof(visit));
	visit[shark.y][shark.x]=true;
	int count=0;
	while(!q.empty()){
		int size=q.size();
		vector<Shark> food;
		for (int k = 0; k < size; ++k)
		{	
			Shark temp;
			temp=q.front();
			q.pop();
			for (int i = 0; i < 4; ++i){
				int ty=dy[i]+temp.y;
				int tx=dx[i]+temp.x;
				if(visit[ty][tx])
					continue;
				if(ty<0||tx<0||tx>=N||ty>=N)
					continue;
				if(map[ty][tx]>shark.size)
					continue;

				Shark tShark=temp;
				tShark.y=ty;
				tShark.x=tx;
				
				if(map[ty][tx]<shark.size && map[ty][tx]>0){
					visit[ty][tx]=true;
					if(food.size()>0){
						if(food[0].y>tShark.y){
							food.pop_back();
							food.push_back(tShark);
						}
						else if(food[0].y==tShark.y){
							if(food[0].x>tShark.x){
								food.pop_back();
								food.push_back(tShark);
							}
						}
					}
					else
						food.push_back(tShark);
				}
				else{
					visit[ty][tx]=true;
					q.push(tShark);
				}
			}
		}
		count++;
		if(food.size()>0){
			eat(food[0],count);
			return true;
		}

	}
	return false;


}

void solve(){
	while(1){
		if(findFood()){
		
		}
		else
			break;
	}
}

int main(){
	input();
	solve();
	cout << shark.cnt;

	
}