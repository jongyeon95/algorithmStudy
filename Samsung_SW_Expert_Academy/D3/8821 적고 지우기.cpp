#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int main(){
	int testcase;
	cin >> testcase;
	bool number[10];
	int cnt=1;
	while(testcase--){
	memset(number,false,sizeof(number));
	int result=0;
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if (number[s[i]-'0'])
		{
			number[s[i]-'0']=false;
		}
		else
			number[s[i]-'0']=true;

	}
	for (int i = 0; i < 10; i++)
	{
		if(number[i])
			result++;
	}
	cout << "#"<<cnt<<" "<<result <<endl;
	cnt++;

	}

}