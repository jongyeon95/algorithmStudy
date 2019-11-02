#include <iostream>
using namespace std;
int main(){
	int n=0;
	int p=10000000;
	int temp;
	for (int i = 0; i < 8; i++)
	{
		cin >> temp;
		n+=p*temp;
		p=p/10;
	}

	if (n==12345678) cout << "ascending";
	else if(n==87654321) cout << "descending";
	else cout << "mixed";
}