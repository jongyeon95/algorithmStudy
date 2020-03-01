#include <iostream>
#include <string>
using namespace std;
int main(){
	int testcase;
	cin >> testcase;
	for (int tc = 1; tc <= testcase; ++tc)
	{
		string s;
		cin >> s;
		long long result=1;
		if(s.size()!=1){
		for (int i = 0; i < s.size(); ++i)
		{
			if(i==0){
				if (s[i]!=s[i+1])
				{
					result*=2;	
				}
			}
			else if(i==s.size()-1){
				if (s[i]!=s[i-1])
				{
					result*=2;
					result%=1000000007;
				}
			}
			else{
				int temp=1;
				if(s[i] != s[i-1]){
					temp++;
					if(s[i] != s[i+1])
						temp++;
					if(s[i-1]==s[i+1])
						temp--;
				}
				else{
					if(s[i]!= s[i+1])
						temp++;
				}


				result*=temp;
				result%=1000000007;
			}
		}
	}
		cout << "#" << tc << " " << result <<"\n";
}
return 0;
}
