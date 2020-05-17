#include <iostream>
using namespace std;
int main(){
	int n;
	int flag=1;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < flag; j++)
		{
			cout<<"*";
		}
		cout<<"\n";
		flag++;
	}
	flag--;
	for (int i = 1; i < n; ++i)
	{
		flag--;
		for (int j = 0; j < flag; j++)
		{
			cout<<"*";
		}
		cout<<"\n";
	}
}