#include <iostream>
#include <string>
using namespace std;


bool IsWin(string win,string my){

	bool Iwin=true;
	for (int i = 0; i < 8; ++i)
	{
		if(win[i]!='*'){
			if(win[i]!=my[i])
				Iwin=false;
		}
	}
	return Iwin;
}

int main(){
	int testcase;
	cin >> testcase;
	for (int t = 1;  t <= testcase; t++)
	{
		int n,m;
		int result=0;
		cin >> n >> m;
		string winNumber[n];
		int winNumberPrice[n];
		string myNumber[m];
		for (int i = 0; i < n; ++i)
		{
			cin >> winNumber[i] >> winNumberPrice[i];
		}

		for (int i = 0; i < m; ++i)
		{
			cin >> myNumber[i];
		}

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if(IsWin(winNumber[i],myNumber[j])){
					result+=winNumberPrice[i];
				}
			}
		}

		printf("#%d %d\n",t,result );

	}
}