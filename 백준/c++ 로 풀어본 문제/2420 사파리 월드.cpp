#include <iostream>
using namespace std;
int main(){
	long long n,m;
	cin >> n>>m;
	long long result=n-m;
	if(result<0)
		cout<<result*-1;
	else
		cout<<result;
}