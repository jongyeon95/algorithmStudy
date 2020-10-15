#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
struct Taxi
{
	int y;
	int x;
	int energy;
};

struct Customer
{
	int y;
	int x;
	int gy;
	int gx;
};

int map[20][20];
bool visited[20][20];
int n,m,k;
int dy[]={0,0,1,-1};
int dx[]={1,-1,0,0};
int answer;
vector<Customer> customer;
Taxi taxi;

bool cmp(Customer a, Customer b){
	if(a.y==b.y)
		return a.x<b.x;
	return a.y<b.y;
}

void input(){
	cin >> n >> m >> k;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> map[i][j];
			if(map[i][j]==1)
				map[i][j]=-1;
		}
	}
	cin>>taxi.y>>taxi.x;
	taxi.y--;
	taxi.x--;
	taxi.energy=k;
	customer.resize(m+1);
	for (int i = 1; i <= m; ++i)
	{
		int a,b,c,d;
		cin >> a>> b >>c >>d;
		map[a-1][b-1]=i;
		Customer C={a-1,b-1,c-1,d-1};
		customer[i]=C;
	}
	answer=0;
}


void find(){

	
	memset(visited,false,sizeof(visited));
	queue<Taxi> q;
	visited[taxi.y][taxi.x]=true;
	q.push(taxi);
	int goalY=0;
	int goalX=0;
	bool findCustomer=false;

	//도착지점에 승객이 있는경우
	if(map[taxi.y][taxi.x]>0){
		findCustomer=true;
		goalY=customer[map[taxi.y][taxi.x]].gy;
		goalX=customer[map[taxi.y][taxi.x]].gx;
		map[taxi.y][taxi.x]=0;
	}


	while(!q.empty()&&!findCustomer){
		if(taxi.energy==0){
			break;
		}
		int size=q.size();
		findCustomer=false;
		vector<Customer> v;
		while(size--){
			Taxi temp=q.front();
			q.pop();
			for (int i = 0; i < 4; ++i)
			{
				int ty=temp.y+dy[i];
				int tx=temp.x+dx[i];

				if(ty<0||tx<0||ty>=n||tx>=n||map[ty][tx]==-1||visited[ty][tx])
					continue;

				if(map[ty][tx]>0){
					findCustomer=true;
					visited[ty][tx]=true;
					v.push_back(customer[map[ty][tx]]);
				}
				else{
					if(temp.energy-1==0){
						visited[ty][tx]=true;
						continue;
					}
					Taxi nTemp={ty,tx,temp.energy-1};
					visited[ty][tx]=true;
					q.push(nTemp);
				}
			}
		}

		taxi.energy--;

		if(findCustomer){
			sort(v.begin(),v.end(),cmp);
			taxi.y=v[0].y;
			taxi.x=v[0].x;
			map[v[0].y][v[0].x]=0;
			goalX=v[0].gx;
			goalY=v[0].gy;
			break;
		}
	}

	if(!findCustomer){
		answer=-1;
		return;
	}

	if(taxi.energy==0){
		answer=-1;
		return;
	}


	
	int startEnergy=taxi.energy;
	memset(visited,false,sizeof(visited));
	queue<Taxi> q2;
	q2.push(taxi);
	bool findGoal=false;
	while(!q2.empty()||!findGoal){
		int size=q2.size();
		while(size--){
			Taxi temp=q2.front();
			q2.pop();
			for (int i = 0; i < 4; ++i)
			{
				int ty=temp.y+dy[i];
				int tx=temp.x+dx[i];
				if(ty<0||tx<0||ty>=n||tx>=n||map[ty][tx]==-1||visited[ty][tx])
					continue;
				if(ty==goalY&&tx==goalX){
					findGoal=true;
					break;
				}
				else{
					if(temp.energy-1==0)
						continue;
					visited[ty][tx]=true;
					Taxi nTemp={ty,tx,temp.energy-1};
					q2.push(nTemp);
				}
			}
		}
		taxi.energy--;
		if(findGoal){
			taxi.y=goalY;
			taxi.x=goalX;
			taxi.energy=(startEnergy-taxi.energy)*2+taxi.energy;
			break;
		}

		if(taxi.energy==0){
			answer=-1;
			return;
		}

	}
	if(!findGoal){
		answer=-1;
		return;
	}

}


void solved(){
	int cnt=m;
	while(answer!=-1&&cnt>0){
		find();
		cnt--;
	}
	if(answer!=-1)
		answer=taxi.energy;

}

int main(){
	input();
	solved();
	cout<<answer;

}