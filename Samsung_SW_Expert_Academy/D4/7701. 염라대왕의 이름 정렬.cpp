#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(string a, string b){
	if(a.size() < b.size()){
		return true;
	}
	else if(a.size() == b.size()){
		if(a<b)
			return true;
		return false;
	}
	return false;

}

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	int testCase;
	cin >> testCase;
	for (int t = 1; t <= testCase; ++t)
	{
		vector<string> v;
		int N;
		cin >> N;
		for (int i = 0; i < N; ++i)
		{
			string s;
			cin >> s;
			v.push_back(s);
		}
		sort(v.begin(),v.end(),cmp);
		cout <<"#"<<t<<"\n";
		for (int i = 0; i < v.size(); ++i)
		{
			if(i!=0){
				if(v[i]==v[i-1])
					continue;
			}
			cout<<v[i]<<"\n";
		}
	}

}