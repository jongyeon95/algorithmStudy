#include <iostream>
using namespace std;
int main(){
	cin.tie(0);
	cout.sync_with_stdio(false);
	int testcase;
	cin >> testcase;
	for (int t = 1; t <= testcase; ++t)
	{
		double p,q;
		cin >> p >> q;
		double s1,s2;
		s1=(1-p)*q;
		s2=p*(1-q)*q;
		cout<<"#"<<t<<" ";
		if(s1<s2)
			cout<<"YES\n";
		else
			cout<<"NO\n";

	}
}