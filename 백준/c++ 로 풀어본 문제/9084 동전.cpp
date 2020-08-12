#include <iostream>
#include <cstring>
using namespace std;


const int MAX = 20;
const int MONEY = 10000;


int N, M;
int coin[MAX];
int dp[MONEY + 1];

 

int solve(void){

        memset(dp, 0, sizeof(dp));
        dp[0] = 1; 
        for (int i = 0; i < N; i++)
               for (int j = coin[i]; j <= M; j++)
                       dp[j] += dp[j - coin[i]];
        return dp[M];
}

 

int main(void){
        int test_case;
        cin >> test_case;
        for (int i = 0; i < test_case; i++)

        {
               cin >> N;
               for (int i = 0; i < N; i++)
                       cin >> coin[i];
               cin >> M;
               cout << solve() << endl;

        }
        return 0;

}


