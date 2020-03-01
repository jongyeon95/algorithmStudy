#include <iostream>
#include <stack>
using namespace std;
int main(){
	int k;
	stack<int> s;
	cin >> k;
	while(k--){
		int temp;
		cin >> temp;
		if(temp==0)
			s.pop();
		else{
			s.push(temp);
		}
	}
	int Ssize=s.size();
	int result=0;
	for (int i = 0; i < Ssize; ++i)
	{
		int temp=s.top();
		s.pop();
		result+=temp;
	}
	if(result==0)
		cout<<0;
	else
		cout << result;
}