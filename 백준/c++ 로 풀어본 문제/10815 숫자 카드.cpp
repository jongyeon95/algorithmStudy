#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	cin.tie(0);

	int N,M;
	cin >> N;
	int arrA[N];
	for (int i = 0; i < N; ++i)
	{
		cin >> arrA[i];
	}
	cin>>M;
	int arrB[M];
	for (int i = 0; i < M; ++i)
	{
		cin >> arrB[i];
	}
	sort(arrA,arrA+N);

	for (int i = 0; i < M; ++i)
	{
		int L=0, R=N;
		int result=0;
		int mid;
		while(L<R){
			mid=(L+R)/2;
			if(arrA[mid]==arrB[i]){
				result=1;
				break;
			}

			if(arrA[mid]<arrB[i]){
				L=mid+1;
			}
			else{
				R=mid;
			}


		}
		cout<<result<<" ";

	}


}