#include <iostream>
#include <string>
using namespace std;
int main(){
	int testcase;
	cin >> testcase;
	for (int t = 1; t <= testcase; ++t)
	{
		int result=0;
		int size;
		cin >> size;
		string correct;
		string sukchan;
		cin >> correct;
		cin >> sukchan;
		for (int i = 0; i < size; ++i)
		{
			if (correct[i]!=sukchan[i])
			{
				result++;
			}
		}

		result=size -result;

		cout  <<"#"<<t<< " " <<result << endl;
	}
}