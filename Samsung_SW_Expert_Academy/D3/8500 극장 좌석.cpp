#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int testcase;
	cin >> testcase;
	for (int t = 1; t <= testcase; ++t)
	{
		vector<int> v;
		int result=0;
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			int temp;
			cin >>temp;
			v.push_back(temp);
		}
		sort(v.begin(),v.end());
		for (int i = 0; i < v.size(); ++i)
		{
			result+=v[i];
		}

		result+=v[v.size()-1];
		result+=n;
		printf("#%d %d \n",t,result);
	}
}