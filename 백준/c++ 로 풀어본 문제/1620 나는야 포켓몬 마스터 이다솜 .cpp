#include <iostream>
#include <map>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,cnt;
	cin >> n >> cnt;
	map<string,string> m;
	for (int i = 1; i <= n; ++i)
	{
		string s;
		cin >> s;
		m.insert({s,to_string(i)});
		m.insert({to_string(i),s});
	}
	for (int i = 0; i < cnt; ++i)
	{
		string s;
		cin >> s;
		cout<<m[s]<<"\n";
	}

}