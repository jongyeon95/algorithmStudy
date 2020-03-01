#include <iostream>
#include <cstring>
using namespace std;
int main(){
	int testcase;
	bool num[10];
	cin >> testcase;
	for (int t = 1; t <= testcase; ++t)
	{
		memset(num,false,sizeof(num));
		string s;
		int result=0;
		cin >> s;
		for (int i = 0; i < s.size(); ++i)
		{
			if(!(num[(int)s[i]-'0'])){
			num[(int)s[i]-'0']=true;
			result++;
			}
		}
		cout <<"#"<<t<<" "<<result<<"\n";



	}
}