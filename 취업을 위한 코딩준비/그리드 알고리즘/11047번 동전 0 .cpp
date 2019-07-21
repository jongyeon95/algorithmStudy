#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int n,k;
	int temp;
	int result=0;
	cin>>n;
	cin>>k;
	int A[n];
	for (int i = 0; i < n; i++)
	{
		cin>>A[i];
	}
	for (int i = n-1; i >= 0; i--)
	{
		if(k/A[i]>0){
			temp=k/A[i];
			result+=temp;
			k=k%A[i];
		}
	}
	cout<<result;



}