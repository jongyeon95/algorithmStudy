#include <iostream>
#include <string>
using namespace std;
int main(){
	int testcase;
	cin>>testcase;
	cin.ignore();
	int cnt=1;
	while(testcase--){
		string s;
		getline(cin,s);
		cout <<"#"<<cnt<<" ";
		for (int i = 0; i < s.size(); i++)
		{
			if(i==0){
				cout<<(char)(s[0]-32);
			}
			else if (s[i]==' ')
			{
				cout<<(char)(s[i+1]-32);
			}
		}
		cout <<"\n";
		cnt++;
	}

}