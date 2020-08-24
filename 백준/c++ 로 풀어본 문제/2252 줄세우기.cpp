#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
vector<int> result;
vector<vector<int>> v;
bool check[32000];
int cnt[32000];


int main(){
	int n,k;
	cin  >> n >> k;
	v.resize(n);
	memset(check,false,sizeof(check));
	memset(cnt,0,sizeof(cnt));
	for (int i = 0; i < k; ++i)
	{
		int a,b;
		cin >> a >> b;
		v[a-1].push_back(b-1);
		cnt[b-1]++;
	}

	while(result.size()<n){
		for(int i=0; i<n; i++){
			if(cnt[i]==0){
				result.push_back(i+1);
				cnt[i]--;
				for (int  j= 0; j< v[i].size(); ++j)
				{
					cnt[v[i][j]]--;
				}
			}
		}

	}

	for (int i = 0; i < n; ++i)
	{
		cout<<result[i]<<" ";
	}

}

//ver 2
/*
#include <iostream>
#include <queue>

using namespace std;

int main () {

    int N, M, a, b, i, temp;
    queue<int> q;
    vector<int> v[32001];

   	cin >> N >> M;
    int indegree[N+1];

    for (i = 0; i < N+1; i++) indegree[i] = 0;


    for (i = 0; i < M; i++) {
       	cin >> a >> b;
        indegree[b]++;
        v[a].push_back(b);
    }

    for (i = 1; i <= N; i++) {
        if (!indegree[i]) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        temp = q.front();
        q.pop();

        cout<<temp<<" ";

        for (i = 0; i < v[temp].size(); i++) {
            indegree[v[temp][i]]--;
            if (!indegree[v[temp][i]]) q.push(v[temp][i]);
        }
    }

    printf("\n");

    return 0;
}
*/