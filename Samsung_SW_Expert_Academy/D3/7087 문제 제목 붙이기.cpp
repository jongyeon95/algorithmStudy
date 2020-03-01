#include <iostream>
#include <string>
using namespace std;
int main(){
	int testcase;
	cin >> testcase;
	
	for (int t = 1; t <= testcase ; ++t)
	{
		int N;
		int result=0;
		
		int ASCII_NUM=65; // 65 ~ 90
		cin >> N;
		string s[N];
		for (int i = 0; i <N; ++i)
			cin >> s[i];
		for (int j = 0; j < 26; j++)
		{
			for (int i = 0; i < N; ++i)
			{
			if((int)s[i][0]==ASCII_NUM){
					result++;
					ASCII_NUM++;
				}
			}
		}
	
		printf("#%d %d\n",t,result);


	}


}