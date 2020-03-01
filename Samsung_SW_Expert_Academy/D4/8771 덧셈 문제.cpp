#include<iostream>
int main(){
	int testcase;
	scanf("%d",&testcase);
	for (int t = 1; t <= testcase; t++)
	{
		long long n,a,b;
		
		scanf("%lld %lld %lld",&n,&a,&b);
		long long result=(n-2)*(b-a)+1;
		if(a>b||(a != b && n == 1))
			result=0;
		printf("#%d %lld\n",t,result);
	}
}