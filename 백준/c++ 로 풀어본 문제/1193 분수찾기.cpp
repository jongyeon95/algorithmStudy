#include <iostream>
using namespace std;

int main(){
	int x;
	int n=0;
	int t=0;
	cin >> x;
	while(1){
		if(x==1)
			break;
		if (x<=t+n)
			break;
		t+=n;
		n++;
	}

	int ans1=x-t;
	int ans2=n+1-ans1;

	if(n%2==0)
		cout<<ans1<<"/"<<ans2;
	else
		cout<<ans2<<"/"<<ans1;

}