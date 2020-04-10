#include <iostream>
using namespace std;
int main(){
	int result=0;
	int n=5;
	while(n--){
		int temp;
		cin >> temp;
		if(temp<40)
			temp=40;
		result+=temp;
	}
	cout << result/5;
}