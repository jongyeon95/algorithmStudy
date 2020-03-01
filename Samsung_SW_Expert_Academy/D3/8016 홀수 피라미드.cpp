#include <iostream>
using namespace std;
int main(){
	int testcase;
	scanf("%d",&testcase);
	for (int t = 1; t <= testcase; ++t)
	{
		long long n,f,b;
		scanf("%lld",&n);
		f=((n-1)*(n-1)+1)*2-1;
		b=(n*n)*2-1;
		if(n==1)
			printf("#%d 1 1\n",t);
		else
			printf("#%d %lld %lld\n",t,f,b);
	}
}