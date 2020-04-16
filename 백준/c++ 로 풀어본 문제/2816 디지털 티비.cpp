#include <iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	int k1Locate=0;
	int k2Locate=0;
	for (int i = 0; i < n; ++i)
	{
		string s;
		cin>>s;
		if(s=="KBS1")
			k1Locate=i;
		else if(s=="KBS2")
			k2Locate=i;
	}
	int inOrder = k1Locate > k2Locate ? 1 : 0;
	for (int i = 0; i < k1Locate; ++i)
	{
		cout<<1;
	}
	for (int i = 0; i < k1Locate; ++i)
	{
		cout<<4;
	}
	for (int i = 0; i < k2Locate+ inOrder; ++i)
	{
		cout<<1;
	}
	for (int i = 0; i < k2Locate+ inOrder-1; ++i)
	{
		cout<<4;
	}
}