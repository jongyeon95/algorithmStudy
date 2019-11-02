#include <iostream>
#include <string>
using namespace std;

int main(){
	string s;
	int result=0;
	int i=0;
	cin >> s;
	while(i<s.length()){// 모든 조건을 넣어봄 
		if (s[i] == 'c' && (s[i+1] == '=' || s[i+1] == '-')) i++;
		else if (s[i] == 'd') {
			if (s[i+1] == '-') i++;
			else if (s[i+1] == 'z' && s[i+2] == '=') i+=2;
		}
		else if ((s[i] == 'l' || s[i] == 'n') && s[i+1] == 'j') i++;
		else if ((s[i] == 's' || s[i] == 'z') && s[i+1] == '=') i++;
		i++; 
		result++;
	}

	cout << result;

}