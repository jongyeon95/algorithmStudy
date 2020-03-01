#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(pair<int,int> p1, pair<int,int> p2){
	if(p1.second==p2.second)
		return p1.first < p2.first;
	return p1.second< p2.second;
}

int main(){
	int n;
	vector<pair<int,int>> v;	
	cin >> n;
	while(n--){
		int a,b;
		cin >> a >> b;
		v.push_back(pair<int,int>(a,b));
	}
	sort(v.begin(),v.end(),cmp);
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i].first << " "<< v[i].second <<"\n"; 
	}

}