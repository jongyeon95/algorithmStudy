#include<iostream>
#include<cmath>
using namespace std;
 
int N;
int MAP[100001][3];
int Max_DP[2][3];
int Min_DP[2][3];
 
void Input()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> MAP[i][j];
        }
    }
}
 
void Solution()
{
    Min_DP[0][0] = Max_DP[0][0] = MAP[1][0];
    Min_DP[0][1] = Max_DP[0][1] = MAP[1][1];
    Min_DP[0][2] = Max_DP[0][2] = MAP[1][2];
 
    for (int i = 2; i <= N; i++)
    {
        Max_DP[1][0] = MAP[i][0] + max(Max_DP[0][0], Max_DP[0][1]);
        Max_DP[1][1] = MAP[i][1] + max(Max_DP[0][0], max(Max_DP[0][1], Max_DP[0][2]));
        Max_DP[1][2] = MAP[i][2] + max(Max_DP[0][1], Max_DP[0][2]);
 
        Max_DP[0][0] = Max_DP[1][0];
        Max_DP[0][1] = Max_DP[1][1];
        Max_DP[0][2] = Max_DP[1][2];
 
        Min_DP[1][0] = MAP[i][0] + min(Min_DP[0][0], Min_DP[0][1]);
        Min_DP[1][1] = MAP[i][1] + min(Min_DP[0][0], min(Min_DP[0][1], Min_DP[0][2]));
        Min_DP[1][2] = MAP[i][2] + min(Min_DP[0][1], Min_DP[0][2]);
 
        Min_DP[0][0] = Min_DP[1][0];
        Min_DP[0][1] = Min_DP[1][1];
        Min_DP[0][2] = Min_DP[1][2];
    }
    
    int Max_Value = max(Max_DP[0][0], max(Max_DP[0][1], Max_DP[0][2]));
    int Min_Value = min(Min_DP[0][0], min(Min_DP[0][1], Min_DP[0][2]));
 
    cout << Max_Value << " " << Min_Value << endl;
}
 
void Solve()
{
    Input();
    Solution();
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    Solve();
 
    return 0;
}