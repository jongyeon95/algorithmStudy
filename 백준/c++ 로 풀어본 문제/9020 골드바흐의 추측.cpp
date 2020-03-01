#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

bool comp(pair<int,int> p1, pair<int,int> p2){
	return p1.second-p1.first<p2.second-p2.first;
}

int main(){
	bool prime[10001];
	vector<int> v;
	memset(prime,true,sizeof(prime));
	for (int i = 2; i < 10001; ++i) // 소수 구별 
	{
		for (int j = i*2; j <10001; j+=i)
		{
			if(prime[j]==false)
				continue;
			prime[j]=false;
		}
	}

	for (int i = 2; i <10001; i++) // 소수만 v 에 추가 
	{
		if(prime[i])
			v.push_back(i);
	}

	int testcase;
	cin >> testcase;
	while(testcase--){
		vector<pair<int,int>> result;
		int num;
		cin >> num;
		for (int i = 0; i < v.size(); i++) // 정답 찾기 
		{
			if(v[i]>num)
				break;
			for (int j = i; j < v.size(); j++)
			{
				if(v[j]>num)
					break;
				if(v[i]+v[j]==num)
					result.push_back(pair<int,int>(v[i],v[j]));

			}
		}

		if(result.size()>1)
			sort(result.begin(),result.end(),comp);	
		cout << result[0].first << " " << result[0].second << "\n";

		}


}