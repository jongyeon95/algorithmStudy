#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int testcase;
	scanf("%d",&testcase);
	for (int t = 1; t <= testcase; ++t)
	{
		int result=0;
		int n,k;
		scanf("%d %d",&n,&k);
		int arr[n];
		for (int i = 0; i < n; ++i)
		{
			int temp;
			scanf("%d",&temp);
			arr[i]=temp;
		}
		sort(arr,arr+n);
		int count=1;
		int bundleMin;
		for (int i = 0; i < n; ++i)
		{
			bundleMin=arr[i];
			count=1;
			for (int j = i+1; j < n; ++j)
			{
					if(arr[j]-bundleMin<=k){
					count++;
				}
				else{
					if(count>result)
						result=count;
				}
			}
			if(count>result)
				result=count;

		}
		printf("#%d %d\n",t,result);

	}
}