#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
using namespace std;

int map[50][50];
bool check[13];
int N,M;
vector<pair<int,int>> chicken;
vector<pair<int,int>> house;
int ans=999999999;
vector<pair<int,int>> v;

void input(){
	cin >> N >> M;
	for(int i=0; i < N; i++){
		for(int j=0; j < N; j++){
			cin >> map[i][j];
			if(map[i][j]==1){
				house.push_back(pair<int,int>(i,j));
			}
			else if(map[i][j]==2){
				chicken.push_back(pair<int,int>(i,j));
			}
		}
	}

}

void dfs(int index){
	if(v.size()==M){

		int result=0;
		for(int i=0; i<house.size(); i++){
			int minN=99999999;
			int hx,hy;
			hy=house[i].first;
			hx=house[i].second;

			for(int j=0; j<v.size();j++){
				int cx,cy;
				cy=v[j].first;
				cx=v[j].second;
				int dis=abs(hx-cx)+abs(hy-cy);

				if(dis<minN)
					minN=dis;
			}

			result+=minN;

			if(result > ans)
				return;
		}

		if(ans>result)
			ans=result;
		return;
	}

	for(int i=index; i<chicken.size(); i++){

		if(!check[i]){
			check[i]=true;
			v.push_back(chicken[i]);
			dfs(i);
			v.pop_back();
			check[i]=false;
		}
	}

	
}

int main(){
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	input();
	dfs(0);
	cout << ans;
}