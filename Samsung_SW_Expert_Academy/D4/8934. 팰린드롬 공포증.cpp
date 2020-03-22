#include <iostream>
#include <string>
using namespace std;
int main(){
	cin.tie(0);
	int testcase;
	cin >> testcase;
	for (int t = 1; t <= testcase; ++t)
	{
		string s;
		int abc[]={0,0,0};
		int minNum;
		cin >> s;
		for (int i = 0; i < s.size(); ++i)
		{
			abc[s[i]-'a']++;
		}
		minNum=abc[0];
		for (int i = 1; i < 3; ++i)
		{
			if(abc[i]<minNum)
				minNum=abc[i];
		}
		bool check=false;
		for (int i = 0; i < 3; ++i)
		{
			abc[i]-=minNum;
			if(abc[i]>1)
				check=true;
		}
		if(!check)
			cout<<"#"<<t<<" YES\n";
		else
			cout<<"#"<<t<<" NO\n";
	}
	
}