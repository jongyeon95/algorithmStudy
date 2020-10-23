#include <iostream>
#include <string>
using namespace std;
bool check=false;

void dfs(string s){
	if(check)
		return;
	if(s.size()==0){
		check=true;
		return;
	}
	if(s.size()==1)
		return;
	
	for (int i = 0; i < s.size(); ++i)
	{
		if(s[i]==s[i+1]){
			int flag=s.size();
			int cnt=0;
			for(int j=i+1; j<s.size(); j++){
				if(s[i]!=s[j]){
					flag=j;
					break;
				}
				cnt++;
			}
			string temp=s.substr(0,i);
			temp+=s.substr(flag);
			dfs(temp);
			i=flag-1;
		}
	}

}


int main(){
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		check=false;
		string s;
		cin >> s;
		if(s.size()!=1)
			dfs(s);
		cout<<check<<endl;
	}
}