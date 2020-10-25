#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main(){
	stack<int>  s;
	int result=0;
	string str;
	cin >> str;
	for(int i=0; i<str.size(); i++){
		if(str[i]=='('){
			s.push(1);
		}
		else{
			s.pop();
			if(str[i-1]==')')
				result+=1;
			else
				result+=s.size();
		}
	}
	cout<< result;

}