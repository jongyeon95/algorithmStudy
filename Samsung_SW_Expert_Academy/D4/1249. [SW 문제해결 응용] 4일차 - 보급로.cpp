#include<iostream>
#include<string>
#include<cstring>
#include<queue>
using namespace std;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int map[100][100];
int dp[100][100];
bool check[100][100];
int N;

int bfs() {
    queue <pair <int, int>> q;
 
    check[0][0] = true;
    dp[0][0] = 0;
 
    q.push(make_pair(0, 0));        // 시작점
 
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
 
        q.pop();
 
        for (int k = 0; k < 4; k++)
        {
            int tx = x + dx[k];
            int ty = y + dy[k];

 			//map 범위 안일때만 실행
            if (tx >= 0 && tx < N && ty >= 0 && ty < N)
            {  
            	// 아직 들리지 않았거나 들릴곳이 현재 위치의 중첩(dp) 값과 갈 곳에 위치값이 합이
            	// 갈 곳의 중첩값보다 작을때 갱신해줌
                if (check[tx][ty] == false || dp[tx][ty] > dp[x][y] + map[tx][ty])
                {
                    check[tx][ty] = true;
                    dp[tx][ty] = dp[x][y] + map[tx][ty];
 
                    q.push(make_pair(tx, ty));
                }
            }
        }
    }        
 
    return dp[N - 1][N - 1];
}


int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        memset(map,0,sizeof(map));
        memset(dp,0,sizeof(dp));
        memset(check,false,sizeof(check));
        cin >> N;
        
        //input
        for(int i=0; i<N; i++){
        	string s;
            cin>>s;
            for(int j=0; j<N; j++){
            	map[i][j]=s[j]-'0';
            }
        }
        
        cout<<"#"<<test_case<<" "<<bfs()<<"\n";
        
        

	}
	return 0;
}