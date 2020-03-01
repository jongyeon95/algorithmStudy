#include <iostream>
using namespace std;
int dp[40] = { 1, 1, };
int fibonacci(int n){
    
    if (n <= 1) return dp[n];       
    else if (dp[n] > 0) return dp[n];   
    return dp[n] = fibonacci(n - 1) + fibonacci(n - 2);
}
 
int main(){
    int T, N;
    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> N;
        if(N == 0) printf("1 0\n");
        else printf("%d %d\n", fibonacci(N - 2), fibonacci(N - 1));    
    }
    return 0;
}
