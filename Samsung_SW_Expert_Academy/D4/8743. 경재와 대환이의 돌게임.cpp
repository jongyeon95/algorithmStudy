#include <iostream>
using namespace std;
int main(){
	cin.tie(0);
	cout.sync_with_stdio(false);

	int testcase;
	cin >> testcase;

	for (int t = 1; t <= testcase; ++t)
	{
		long long R, B;
		cin >> R >> B;
		R=R-B;
		if(R<0)
			R=(-1)*R;
		if(R<2)
			cout<<"#"<<t<<" "<<"DH"<<"\n";
		else
			cout<<"#"<<t<<" "<<"KJ"<<"\n";
	}
}