#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<string,int>> v;

string numToEng[]={"zero","one","two","three","four","five","six","seven","eight","nine"};



int main(){
	int n,m;
	cin >> n >> m;
	for(int i=n; i<=m; i++){
		int temp=i;
		string s="";
		while(temp>=10){
			s+=numToEng[temp/10];
			s+=" ";
			temp%=10;
		}
		s+=numToEng[temp];
		v.push_back({s,i});
	}
	sort(v.begin(),v.end());
	int cnt=0;
	for (int i = 0; i < v.size(); ++i)
	{
		cout<<v[i].second<<" ";
		cnt++;
		if(cnt==10){
			cnt=0;
			cout<<"\n";
		}
	}


}