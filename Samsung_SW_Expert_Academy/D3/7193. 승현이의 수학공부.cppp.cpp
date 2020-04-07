#include <iostream>
#include <string>
using namespace std;
int main(){
	cin.tie(0);
	cout.sync_with_stdio(false);
	int testcase;
	cin >> testcase;
	for (int t = 1; t <= testcase; ++t)
	{
		int n;
		string x;
		cin >> n >> x;
		int temp=0;
		int flag=1;
		for (int i = x.size()-1; i >= 0; i--)
		{
			temp+=(x[i]-'0');
		}
		cout<<"#"<<t<<" "<<temp%(n-1)<<"\n";
	}
}