#include <iostream>
#include <string>
using namespace std;

int CharSameNum(char a){
	int returnNum=1;
	if(a=='A'||a=='D'||a=='O'||a=='P'||a=='Q'||a=='R')
		returnNum=2;
	else if(a=='B')
		returnNum=3;

	return returnNum;
}

int main(){
	int testcase;
	cin >> testcase;
	for (int t = 1; t <= testcase; ++t)
	{
		bool IsTrue=true;
		string a;
		string b;
		cin >> a >>b;
		if(a.size()!=b.size()){
			printf("#%d DIFF\n",t);
			continue;
		}

		for (int i = 0; i < a.size(); ++i)
		{
			if(CharSameNum(a[i])!=CharSameNum(b[i])){
				IsTrue=false;
				break;
			}
		}
		if(IsTrue)
			printf("#%d SAME\n",t);
		else
			printf("#%d DIFF\n",t);

	}

}