#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<pair<pair<int,int>,int>> v;
	for (int i = 0; i < n; i++)
	{
		int t1,t2;
		cin >>t1 >> t2;
		v.push_back(pair<pair<int,int>,int>{{t1,t2},1});
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if(i==j){ continue ;}
			if((v[i].first.first<v[j].first.first)&&(v[i].first.second<v[j].first.second)){
				v[i].second+=1;
			}
			
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << v[i].second << " ";
	}

}