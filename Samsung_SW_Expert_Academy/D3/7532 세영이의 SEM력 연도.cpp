#include <iostream>
using namespace std;
int S, E, M;
int n;

int main(){
	int testcase;
	scanf("%d",&testcase);
	for (int t = 1; t <= testcase; ++t)
	{
		int S, E, M;
		int result=0;
		n=1;
		scanf("%d %d %d",&S,&E,&M);
		if(S==E&&E==S&&S==M){
			printf("#%d %d\n",t,S);
			continue;
		}
		result=S;
		while(1){
			if((result-E)%24==0&&(result-M)%29==0)
			{
				break;
			}
			else
				result+=365;
		}
		printf("#%d %d\n",t,result);

	}
}