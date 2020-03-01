#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;
int main(){
	int testcase;
	cin >> testcase;
	for (int t = 0;t < testcase; ++t)
	{
		string s;
		cin >> s;
		stack<char> result;
		stack<char> buffer;
		
		for (int i = 0; i < s.size(); ++i)
		{
			if(s[i]=='<'){
				if(result.size()>0){
				buffer.push(result.top());
				result.pop();
				}
			}
			else if(s[i]=='>'){
				if(buffer.size()>0){
				result.push(buffer.top());
				buffer.pop();
				}
			}
			else if(s[i]=='-'){
				if(result.size()>0)
					result.pop();
			}
			else{
				result.push(s[i]);
			}
		}
		if(buffer.size()>0){
			while(!buffer.empty()){
				result.push(buffer.top());
				buffer.pop();
			}
		}
		int resultsize=result.size();
		
		for (int i = 0;i< resultsize; i++)
		{
			buffer.push(result.top());
			result.pop();
		}

		for (int i = 0;i<resultsize; i++)
		{
			cout <<buffer.top();
			buffer.pop();
		
		}
		cout << endl;


	}

}
