#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;


bool cmp(pair<string,int> p1,pair<string,int> p2){
	if(p1.second==p2.second){
		return p1.first.compare(p2.first)<0;
	}
	return p1.second>p2.second;
}

int alpha(string temp){
	bool alphabet[26];
	int result=0;
	memset(alphabet,false,sizeof(alphabet));
	for (int i = 0; i < temp.size(); ++i)
	{
		if(temp[i]==' ')
			continue;
		if(!alphabet[temp[i]-'A']){
			alphabet[temp[i]-'A']=true;
			result++;
		}
	}
	return result;

}

int main(){
	cin.tie(0);
	cout.sync_with_stdio(false);
	int testcase;
	cin >> testcase;
	for (int t = 1; t <=testcase; ++t)
	{
		int n;
		cin >> n;
		vector<pair<string,int>> v;
		cin.ignore();
		for (int i = 0; i < n; ++i)
		{
			string temp;
			getline(cin,temp);
			v.push_back({temp,alpha(temp)});
		}

		sort(v.begin(),v.end(),cmp);
		cout <<"#"<<t<<" "<<v[0].first<<"\n";

	}
}