#include <iostream>
using namespace std;
int main(){
	int testcase;
	scanf("%d",&testcase);
	for (int t = 1; t <= testcase; t++)
	{
		int p,max,min;
		max=0;
		min=1000000;
		int temp=0;
		int result=0;
		scanf("%d",&p);
		for (int i = 0; i < p; ++i)
		{
			scanf("%d",&temp);
			if(temp>max)
				max=temp;
			if(temp<min)
				min=temp;
		}
		result=max*min;

		printf("#%d %d\n",t,result);
	}
}