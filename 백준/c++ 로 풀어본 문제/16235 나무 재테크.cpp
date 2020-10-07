#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct tree
{
	int age;
	bool alive;
};
int n,m,k;
int food[10][10];
int addFood[10][10];
int dy[]={-1, -1, -1, 0, 0, 1, 1, 1};
int dx[]={-1,  0,  1,-1, 1,-1, 0, 1};
int answer=0;
vector<tree> area[10][10];

bool cmp(tree a, tree b){
	return a.age<b.age;
}

void init(){
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			food[i][j]=5;
			cin >> addFood[i][j];
		}
	}
	for (int i = 0; i < m; ++i)
	{
		int a,b,c;
		cin >> a >> b >> c;
		a--;
		b--;
		area[a][b].push_back({c,true});
	}

}

void eatAndDead(int i, int j){
	sort(area[i][j].begin(), area[i][j].end(), cmp);
	bool check=true;
	for (int z = 0; z < area[i][j].size(); ++z)
	{

		if(check){
			if(area[i][j][z].age<=food[i][j]){
				food[i][j]-=area[i][j][z].age;
				area[i][j][z].age+=1;
			}
			else{
				check=false;
				food[i][j]+=area[i][j][z].age/2;
				area[i][j].erase(area[i][j].begin()+z);
				z--;
			}
		}
		else{
			food[i][j]+=area[i][j][z].age/2;
			area[i][j].erase(area[i][j].begin()+z);
			z--;
		}
	}
	
}


void born(int y, int x){
	for (int i = 0; i < 8; ++i)
	{
		int ty=y+dy[i];
		int tx=x+dx[i];
		if(ty<0||tx<0||ty>=n||tx>=n){
			continue;
		}
		area[ty][tx].push_back({1,true});
	}
}

int main(){
	cin >> n >> m >> k;
	init();
	while(k--){
		///spring and summer
		for(int i=0; i<n; i++){
			for (int j = 0; j < n; ++j)
			{
				if(area[i][j].size()>0){
					eatAndDead(i,j);
				}
			}
		}


		//fall
		for(int i=0; i<n; i++){
			for (int j = 0; j < n; ++j)
			{
				if(area[i][j].size()>0){
					for (int z = 0; z< area[i][j].size(); ++z)
					{
						if(area[i][j][z].age%5==0){
							born(i,j);
						}
					}
				}
			}
		}

		///winter
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				food[i][j]+=addFood[i][j];
			}
		}

	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			
			answer+=area[i][j].size();
		}
		
	}
	cout<<answer;
}