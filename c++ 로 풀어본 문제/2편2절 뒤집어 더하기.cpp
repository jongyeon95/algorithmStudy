#include <iostream>
#include <string>
using namespace std;

int main(){
	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++)
	{
		string num;
		string rnum;
		cin >> num;

		for (int j = 0; j < num.length(); j++)
		{
			rnum[num.length()-j-1]=num[j];
		}

		int inum=stoi(num);
		int irnum=stoi(rnum);
		int sumnum=inum+irnum;
		string result=to_string(sumnum);
		bool resultflag = true;
		for (int j = 0; j < result.length()/2; j++)
		{
			if(result[j]==result[result.length()-1]){				 
			}
			else{
				resultflag= false;
				break;
			}
		}
		if (resultflag)
		{
			cout << "yes" << endl;
		}
		else
			cout << "no" << endl;


	}
}