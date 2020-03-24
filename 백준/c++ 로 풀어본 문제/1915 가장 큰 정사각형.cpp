#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int n, m, arr[1001][1001], dp[1001][1001], result;
string s;
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) {
            arr[i][j] = s[j] - 48;
            if (arr[i][j] == 1) {
                dp[i][j] = 1;
                result = 1;
            }
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (arr[i - 1][j] == 1 && arr[i - 1][j - 1] == 1 && arr[i][j - 1] == 1) {
                dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]);
                dp[i][j] = min(dp[i][j], dp[i][j - 1]) + 1;
            }
            result = max(result, dp[i][j]);
        }
    }
    cout << result*result << endl;
}

