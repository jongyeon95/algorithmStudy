#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
 
int N, M;
int MAP[300][300];
int C_MAP[300][300];
bool Visit[300][300];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
 
 
void BFS(int a, int b)
{
    queue<pair<int, int>> q;
    q.push({a,b});
    Visit[a][b] = true;
 
    while (q.empty() == 0)
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
 
        for (int i = 0; i < 4; i++)
        {
            int tx = x + dx[i];
            int ty = y + dy[i];
 
            if (tx >= 0 && ty >= 0 && tx < N && ty < M)
            {
                if (Visit[tx][ty] == false && MAP[tx][ty] != 0)
                {
                    Visit[tx][ty] = true;
                    q.push(make_pair(tx, ty));
                }
            }
        }
    }
}
 
int Melt(int x, int y)
{
    int Cnt = 0;
    for (int i = 0; i < 4; i++)
    {
        int tx = x + dx[i];
        int ty = y + dy[i];
 
        if (MAP[tx][ty] == 0) Cnt++;
    }
    return Cnt;
}
 
 
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> MAP[i][j];  
    int Year = 0;
    while (1)
    {
        int Land_Cnt = 0;
        memset(Visit, false, sizeof(Visit));
        memset(C_MAP, 0, sizeof(C_MAP));
        
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (MAP[i][j] != 0 && Visit[i][j] == false)
                {
                    Land_Cnt++;
                    BFS(i, j);
                }
            }
        }
 
        if (Land_Cnt >= 2) { cout << Year << endl; break; }
        if (Land_Cnt == 0) { cout << 0 << endl; break; }
 
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (MAP[i][j] != 0)
                {
                    C_MAP[i][j] = MAP[i][j] - Melt(i, j);
                    if (C_MAP[i][j] < 0) C_MAP[i][j] = 0;
                }
            }
        }        
 
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                MAP[i][j] = C_MAP[i][j];
            }
        }
 
        Year++;
    }
 
    return 0;
}

