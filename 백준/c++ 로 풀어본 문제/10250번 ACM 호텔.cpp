#include <iostream>
using namespace std;
int main(){
	int testcase,h,w,n;
	cin >> testcase;
	while(testcase--){
		cin >> h >> w >> n;
		n--;
		int result=0;
		result+=(n/h+1)+((n%h+1)*100);
		cout << result << endl;
	}

}