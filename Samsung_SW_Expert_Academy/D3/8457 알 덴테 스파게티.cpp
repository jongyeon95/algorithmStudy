#include <iostream>
#include <cmath>

using namespace std;
int main(){
    int testcase;
    cin >> testcase;
    for(int i=1;i<=testcase; i++){
        int n,b,e;
        int result=0;
       
        cin >> n >> b >> e;
        for(int j=0; j<n; j++){
        	int temp;
            cin >> temp;
            int cnt=1;
            if(temp<=b+e){
                for(int k=temp; k<=b+e; k+=temp){
                	if(k>=b-e&&k<=b+e){
                        result++;
                        break;
                    }
                }
            }
        }
        cout <<"#"<<i<<" "<<result<<endl;
        
        
    }

}