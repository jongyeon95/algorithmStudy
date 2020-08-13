#include <iostream>
using namespace std;



int main(){
	int test_case;
	cin >> test_case;
	int n,m;
	for (int t = 0; t < test_case; ++t)
	{	
		cin >> n >> m;
	
		int a,b;
		for (int i = 0; i < m; ++i)
		{
			cin >> a >> b;
		}
		cout<<n-1<<"\n";
	}

}