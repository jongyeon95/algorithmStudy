#include <iostream>
#include <string>
using namespace std;
int main(){
	string s;
	int result=1;
	getline(cin , s);
	for (int i = 0; i < s.size()-1; i++)
	{
		if(s[i+1]==' ')
			result++;
	}

	if(s[s.size()-1]==' ')
		result--;

	cout << result;

}