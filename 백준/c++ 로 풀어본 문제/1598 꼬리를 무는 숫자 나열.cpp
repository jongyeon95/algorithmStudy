#include <iostream>
#include <cmath>
using namespace std;
int main(){
	int a,b;
	cin >> a >> b;
	int l,h;
	a--;
	b--;
	l=abs(a/4-b/4);
	h=abs(a%4-b%4);

	cout<<l+h;
}