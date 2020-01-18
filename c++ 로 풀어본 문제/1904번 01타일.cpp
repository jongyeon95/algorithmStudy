#include <iostream>
using namespace std;
int main(){

	int n;
	cin >> n;
	if(n==1){
        cout << 1;
        return 0;
	}
	else if(n==2){
        cout << 2;
        return 0;
	}
	else{
    int a1=1;
    int a2=2;
    int result=0;
	for (int i = 3; i <= n; ++i)
	{
	    result=(a1+a2)%15746;
	    a1=a2%15746;
	    a2=result%15746;
	}
	cout << result;
    }
    return 0;
}
