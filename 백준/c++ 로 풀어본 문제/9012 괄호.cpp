#include <iostream>
#include <string>
using namespace std;

int main(){
	string s;
	int testcase;
	cin >>testcase;
	while(testcase--){
	cin >> s;
	int PSCheck=0;
	bool result=true;
	for (int i = 0; i < s.size(); ++i)
	{
		if(PSCheck<0){
			result=false;
			break;
		}
		else if(s[i]=='(')
			PSCheck++;
		else
			PSCheck--;

	}
	if (PSCheck!=0)
	{
		result=false;
	}

	if(result)
		cout <<"YES"<<endl;
	else
		cout <<"NO"<<endl;
		}



}