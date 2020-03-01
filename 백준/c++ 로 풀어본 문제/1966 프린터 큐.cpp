#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int v1,int v2){
	return v1>v2;
}

int main(){
	int testcase;
	cin >> testcase;
	while(testcase--){
		int n,m,temp;
		cin >> n>>m;
		vector<pair<int,int>> v;
		vector<int> cmpv;
		for (int i = 0; i < n; ++i)
		{
			cin >> temp;
			v.push_back(pair<int,int>(i,temp));
			cmpv.push_back(temp);
		}
		sort(cmpv.begin(),cmpv.end(),cmp);
		int j=0;
		int cnt=1;
		for (int i = 0; i < v.size(); i++)
		{
			if(v[i].second==cmpv[j]){
				if(v[i].first==m){
					cout << cnt << endl;
					break;
				}
				else{
					j++;
					cnt++;
				}
			}
			else{
				v.push_back(pair<int,int>(v[i].first,v[i].second));
			}
		}
		
	}
}
