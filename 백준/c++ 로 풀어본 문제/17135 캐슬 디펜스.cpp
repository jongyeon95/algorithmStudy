#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cstring>
#include <deque>
using namespace std;
int n,m,d;
int dy[]={0,-1,0};
int dx[]={1,0,-1};
deque<deque<int>> map;
deque<int> blank;
vector<int> archer;
int answer;

void input(){
	cin >> n >> m >> d;
	map.resize(n);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			int temp;
			cin >> temp;
			map[i].push_back(temp);
		}
	}
	for (int i = 0; i < m; ++i)
	{
		blank.push_back(0);
	}
	answer=0;

}

bool cmp(pair<int, int> a,pair<int, int> b){
	return a.second<b.second;
}

pair<int , int> findTarget(int flag,deque<deque<int>> tempMap){

	vector<pair<int,int>> v;
	bool visited[n][m];
	memset(visited,false,sizeof(visited));
	tempMap.push_back(blank);
	int y=tempMap.size()-1;
	int x=flag;
	
	queue<pair<int,int>> q;
	q.push(make_pair(y,x));
	int cnt=0;
	while(!q.empty()){
		if(cnt>=d){
			return make_pair(-1,-1);
			tempMap.pop_back();
		}
		int size=q.size();
		bool check=false;
		while(size--){
			pair<int, int> temp=q.front();
			q.pop();
			for (int i = 0; i < 3; ++i)
			{
				int ty=temp.first+dy[i];
				int tx=temp.second+dx[i];
				if(ty<0||tx<0||ty>=n||tx>=m||visited[ty][tx])
					continue;
				if(tempMap[ty][tx]==1){
					check=true;
					v.push_back(make_pair(ty,tx));
					visited[ty][tx]=true;
				}
				else{
					visited[ty][tx]=true;
					q.push(make_pair(ty,tx));
				}

			}
			
		}
		cnt++;
		if(check)
			break;
	}
	if(v.size()==0){
		return make_pair(-1,-1);
	}
	sort(v.begin(),v.end(),cmp);
	tempMap.pop_back();
	return v[0];
}

void solved(){
	deque<deque<int>> tempMap=map;
	int score=0;
	int count=n;
	while(count--){
		vector<pair<int,int>> v;
		for(int i=0; i<archer.size(); i++){
			v.push_back(findTarget(archer[i],tempMap));
		}



		for (int i = 0; i < v.size(); ++i)
		{
			if(v[i].first==-1)
				continue;
			if(tempMap[v[i].first][v[i].second]==1){
				score++;
				tempMap[v[i].first][v[i].second]=0;
			}
		}

		tempMap.pop_back();
		tempMap.push_front(blank);
	}

	
	

	if(answer<score){
		answer=score;
	}
	return;
}

void dfs(int index, int cnt){

	if(cnt>=3){
		solved();
		return;
	}

	for (int i = index; i < m; ++i)
	{
		archer.push_back(i);
		dfs(i+1,cnt+1);
		archer.pop_back();
	}
}


int main(){
	input();
	dfs(0,0);
	cout<<answer;


}