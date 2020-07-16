#include <iostream>
#include <cstring>
using namespace std;
int n, ans, sum;
int stone[1000];
int main(){
    cin.tie(0);
    cout.sync_with_stdio(false);
    int T;
    cin >> T;
    for(int test = 1; test <= T; test++){
        sum = 0;
        ans = 0;
        
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> stone[i];
            sum ^= stone[i];
        }
        
        if(sum != 0){
            for(int i=0; i<n; i++){
                int temp = sum^stone[i];
                if((sum ^ stone[i]) <= stone[i])
                    ans++;
            }      
        }
        cout << "#" << test << " "<< ans << "\n";
    }
    
}