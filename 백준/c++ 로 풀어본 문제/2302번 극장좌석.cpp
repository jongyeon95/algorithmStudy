#include <iostream>

using namespace std;

int dp[41];

int main()
{
    int n, m, in, pre = 0;
    int result = 1;
  	cin >> n >> m;
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
        dp[i] = dp[i-1] + dp[i-2];
    if (m)
    {
        for (int i = 0; i < m; i++)
        {
         	cin >>in;
            result *=dp[in-pre-1];
            pre = in;
        }
        result *= dp[n-in];
    }
    else
        result = dp[n];
   	cout << result;
    return 0;
}