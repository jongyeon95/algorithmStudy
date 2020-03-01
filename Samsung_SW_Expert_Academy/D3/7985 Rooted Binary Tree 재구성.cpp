#include <iostream>
#include <cmath>
#include <deque>
using namespace std;
int main(){
	int testcase;
	scanf("%d",&testcase);
	for (int t = 1; t <= testcase; ++t)
	{
		int n,temp;
		int TreeSize;
		deque<int> dq;
		deque<int> result;
		scanf("%d",&n);
		TreeSize=pow(2,n)-1;
		for (int i = 0; i < TreeSize; ++i)
		{
			scanf("%d",&temp);
			dq.push_back(temp);
		}
		printf("#%d ",t);
		int popflag1=pow(2,n-1);
		int popflag2=0;

		while(dq.size()>0){
			result.push_back(dq.front());
			dq.pop_front();
			
			popflag2++;
			if(popflag1!=popflag2){
				dq.push_back(dq.front());
				dq.pop_front();
			}
			else{
				popflag1/=2;
				popflag2=0;
			}
			
		}
		int flag1=TreeSize;
		int flag2=1;
		for (int i = 0; i <n; i++)
		{
			for (int j = flag1-flag2;  j < flag1; j++)
			{
				printf("%d ",result[j]);
			}
			printf("\n");
			flag1-=flag2;
			flag2*=2;
		}

	}
}