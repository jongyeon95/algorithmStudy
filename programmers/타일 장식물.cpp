#include <string>
#include <vector>

using namespace std;
long long dp[80];
long long solution(int N) {
    dp[0]=1;
    dp[1]=1;
    long long answer = 0;
    for(int i=2; i<N; i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    answer=dp[N-1]*4+dp[N-2]*2;
    return answer;
}