#include <iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	n%=6;
	if(n%2==0)
		cout<<"SK";
	else
		cout<<"CY";
}