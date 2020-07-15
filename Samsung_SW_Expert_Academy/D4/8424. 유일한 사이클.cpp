#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int N, cnt = 0;
        vector<vector<int> > map;
        vector<int> finished, visited;
        queue<int> q;

        //input
        cin >> N;
        map.resize(N);
        finished.resize(N,0);
        visited.resize(N,0);
        int a,b,i;

        for (i = 0; i < N; ++i)
        {
            cin >> a >> b;
            a--; b--;
            map[a].push_back(b);
            map[b].push_back(a);

            finished[a]++;
            finished[b]++;
        }        
        
        for (int i = 0; i < N; ++i)
        {
            if (!visited[i] && (finished[i] == 1)) 
            {
                q.push(i);

                while (!q.empty())
                {
                    int now = q.front(); 
                    q.pop();

                    if (!visited[now] && (finished[now] == 1)) 
                    {
                        visited[now] = true;
                        cnt++;

                        for (int flag=0; flag<map[now].size(); flag++)
                        {
                            finished[map[now][flag]]--;
                            q.push(map[now][flag]);
                        }   
                    }
                }
            }
        }

        cout << "#" << test_case << " " << N-cnt << "\n";

	}
	return 0;
}