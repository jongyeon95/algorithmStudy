#include <iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	int plug[n];
	int sum=0;
	for (int i = 0; i < n; ++i)
	{
		cin >> plug[i];
	}

	for (int i = 0; i < n-1; ++i)
	{
		plug[i]--;
		sum+=plug[i];
	}
	sum+=plug[n-1];
	cout<<sum;
}