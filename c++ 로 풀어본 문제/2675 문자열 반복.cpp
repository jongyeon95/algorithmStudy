#include <iostream>
#include <string>
using namespace std;

int main(){
	int testCase;
	int sizeString;
	
	cin >> testCase;
	for (int i = 0; i < testCase; i++)
	{
		string s;
		cin>>sizeString;
		cin>>s;
		for (int j = 0; j < s.size(); j++)
		{
			for (int k = 0; k < sizeString; k++)
			{
				cout<<s[j];
			}
		}
		cout <<"\n";
	}
}