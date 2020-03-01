#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int main(){
	int n;
	int result=0;
	cin >> n;
	while(n--){
		string s;
		bool alphabet[26];
		bool check=true;
		memset(alphabet,true,sizeof(alphabet));
		cin >> s;
		for (int i = 0; i < s.size(); ++i)
		{
			if(!alphabet[s[i]-97]){
				check=false;
				break;
			}
			else{
				if(s[i]==s[i+1])
					continue;
				else
					alphabet[s[i]-97]=false;

			}
		}
		if(check)
			result++;


	}
	cout << result;

}