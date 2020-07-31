#include <iostream>
using namespace std;


int main(){
	int n,m;
	cin >> n >> m;
	int arr[n];
	long long max=0;
	long long mid=0;
	
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
		if(max<arr[i])
			max=arr[i];
	}
	long long l=0 ,r=max;
	long long result=0;

	while(l<r){

		mid=(l+r)/2;
		long long sum=0;
		for (int i = 0; i < n; ++i)
		{
			if(arr[i]-mid<0)
				continue;
			sum+=arr[i]-mid;
		}
		if(sum<m){
			r=mid;
		}
		else{
			result=mid;
			l=mid+1;
		}
	}
	cout<<result;
}