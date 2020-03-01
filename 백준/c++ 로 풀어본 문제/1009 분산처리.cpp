#include <iostream>

using namespace std;
int main(){
	int testcase;
	cin >> testcase;
	while(testcase--){
		int a,b;
		int num;
		cin >> a >> b;
		num=a;
		for(int i=0; i<b-1;i++){
			num*=a;
			num%=10;
			if(num==0)
				break;
		}
		if(num==0)
			cout << 10 <<endl;
		else
			cout << num <<endl;
	}
}