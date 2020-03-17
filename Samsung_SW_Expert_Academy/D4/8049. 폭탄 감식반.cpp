#include <iostream>
#include <string>
using namespace std;

bool IsBoom(string a){
	if(a.size()<4)
		return false;
	if(a[1]=='M')
		return false;
	if(a[a.size()-1]=='C')
		return false;
	return true;
}

int main(){
	cin.tie(0);
	cout.sync_with_stdio(false);
	int testcase;
	cin >> testcase;
	for (int t = 1; t <= testcase; ++t)
	{
		string s;
		cin >> s;
		bool result= false;
		if(IsBoom(s)){
			int flag=1;
			result=true;
			while(flag<s.size()){
			if(s[flag]=='F'){
				while(s[flag]=='F'&&flag<s.size()){
					flag++;
				}
				if(s[flag]!='M'||s[flag+1]!='C'){
					result=false;
					break;
				}
				else{
					flag+=2;
					while(s[flag]=='M'&&flag<s.size()){
						flag++;
					}
				}

			}
			else if(s[flag]=='C'){
				while(s[flag]=='C'&&flag<s.size()){
					flag++;
				}
				if(s[flag]!='M'||s[flag+1]!='F'){
					result=false;
					break;
				}
				else{
					flag+=2;
				}

			}
			else{
				result=false;
					break;
			}
			flag++;
			}

		}
		cout <<"#"<<t<<" ";
		if(result)
			cout<<"DETECTED!\n";
		else
			cout<<"NOTHING!\n";

	}

}