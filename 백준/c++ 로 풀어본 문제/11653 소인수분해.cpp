#include <iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	int cnt=2;
	while(1){
		if(n%cnt==0){
			cout<<cnt<<"\n";
			n/=cnt;
		}
		else{
			if(n==1)
				break;
			if(n<cnt){
				cout<<n;
				break;
			}
			cnt++;
		}
	}
}