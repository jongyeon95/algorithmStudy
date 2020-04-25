#include <iostream>
#include <string>
using namespace std;
#define mod 1000000
int main(void){
 
    string s;
    int sSize;
    int Dp[5010] = {};
    Dp[0] = 1;
    Dp[1] = 1;
    cin >> s;
    sSize = s.size();
    if(s[0]=='0'){
    	cout<<0;
    	return 0;
    }
 
    for (int i = 2; i <= sSize; i++)
    {
        int now = i - 1;
        if (s[now] > '0')
            Dp[i] = Dp[i - 1] % mod;
 
        int x = (s[now- 1]-'0') * 10 + s[now]-'0';
        
        if (10 <= x && x <= 26)
            Dp[i] = (Dp[i] + Dp[i - 2]) % mod;
    }
   cout << Dp[sSize];
 
}

