#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
bool cmp(pair<pair<int,string>,int> p1,pair<pair<int,string>,int> p2){

	if(p1.first.first==p2.first.first)
		return p1.second < p2.second;
	else
		return p1.first.first<p2.first.first;
}
int main(){
	int n;
	cin>>n;
	vector<pair< pair<int,string>,int>> v;
	for (int i = 0; i < n; ++i)
	{
		int age;
		string s;
		cin >> age >> s;
		v.push_back(pair<pair<int,string>,int>(pair<int,string>(age,s),i));
	}
	sort(v.begin(),v.end(),cmp);
	for (int i = 0; i < n; ++i)
	{
		cout << v[i].first.first <<" "<<v[i].first.second<<"\n";
	}

}