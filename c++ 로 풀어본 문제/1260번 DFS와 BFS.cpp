#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int map[1001][1001];
int v[1001];
int n,m,s;
queue<int> q;
void dfs(int idx){

	cout << idx << " ";
	for (int i = 1; i <= n; i++)
	{
		if(map[idx][i] && !v[i]){
			v[i]=1;
			dfs(i);
		}
	}
}
void bfs(int idx){
	q.push(idx);
	v[idx] = 1;
	while (!q.empty()){
		idx = q.front();
		q.pop();
		cout << idx << " ";
		for(int i=1; i<=n; i++)
			if (map[idx][i] && !v[i]){
				v[i] = 1;
				q.push(i);
			}	
	}
}

int main(){
	
	cin >> n >> m >> s;
	for (int i = 0; i < m; i++)
	{
		int tmp1,tmp2;
		cin >> tmp1 >>tmp2;
		map[tmp1][tmp2]=1;
		map[tmp2][tmp1]=1;	
	}

		v[s] = 1; 
        dfs(s);
        cout << endl;
        memset(v, false, sizeof(v));
        bfs(s);
        cout << endl;
        return 0;


}