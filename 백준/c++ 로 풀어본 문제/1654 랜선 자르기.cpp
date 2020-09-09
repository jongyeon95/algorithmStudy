#include <iostream>
#include <algorithm>
using namespace std;
long long lan[10000];
long long k,n;

long long binarySearch(){
	sort(lan,lan+k);
	long long l=1;
	long long r=lan[k-1];
	long long mid=(1+r)/2;
	while(r>=l){
		long long sum=0;
		mid=(l+r)/2;
		for(long long i=0; i<k; i++){
			sum+=lan[i]/mid;
		}
		if(sum>=n){
			l=mid+1;
		}
		else{
			r=mid-1;
		}

	}
	return r;

}

int main(){
	cin >> k >> n;
	for (int i = 0; i < k; ++i)
		cin >> lan[i];
	cout<<binarySearch();


}