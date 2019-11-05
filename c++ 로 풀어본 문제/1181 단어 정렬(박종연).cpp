#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(pair<string,int> p1, pair<string,int> p2){
	if (p1.second==p2.second)
	{
		return p1.first< p2.first;
	}
	return p1.second < p2.second;
}


int main(){
	vector<pair<string,int>> v;
	int n;

	cin >> n;
	for(int i=0; i<n;i++){
		string s;
		cin>>s;
		v.push_back(pair<string,int>(s,s.size()));
	}
	sort(v.begin(),v.end(),comp);
	cout<<v[0].first<<"\n";
	for (int i = 1; i < n; i++)
	{
		if(v[i].first!=v[i-1].first)
			cout<<v[i].first<<"\n";
	}

}