#include <iostream>



int main(){
	int testcase;
	scanf("%d",&testcase);
	for (int i = 1; i <= testcase; i++)
	{
		long long result=0;
		long long num;
		scanf("%lld",&num);
		
		
		result=((num-1)/2)*((num-1)/2);
		printf("#%d %lld\n",i,result);
	}
	return 0;
}
