#include <iostream>
using namespace std;
int minNum(int a, int b){
	if(a<=b)
		return a;
	return b;
}

int main(){
	int dp[100001];
	int n;
	cin >> n;
	for(int i=1; i<=n; i++){
        dp[i] = i;
        for(int j=1; j*j<=i; j++){
            dp[i] = minNum(dp[i],dp[i-j*j] + 1);
        }
    }
    cout << dp[n];
}