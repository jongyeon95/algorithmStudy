#include <iostream>
using namespace std;
int main(){
	int testcase;
	scanf("%d",&testcase);
	for (int t = 1; t <= testcase; ++t)
	{
		int n;
		int UpResult,DownResult;
		UpResult=0;
		DownResult=0;
		scanf("%d",&n);
		int arrN[n];
		for (int i = 0; i < n; ++i)
		{
			scanf("%d",&arrN[i]);
		}
		for (int i = 0; i < n-1; ++i)
		{
			int temp=arrN[i]-arrN[i+1];
			if(temp>0){
				if (DownResult<temp)
						DownResult=temp;
			}
			else{
				temp*=-1;
				if (UpResult<temp)
						UpResult=temp;
			}

		}
		printf("#%d %d %d\n",t,UpResult,DownResult);

	}
}