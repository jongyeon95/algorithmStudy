#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int n,m;
	int max=0;
	int temp=0;
	cin>>n>>m;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i]; 
	}
	sort(arr,arr+n);
	for (int i = 0; i < n; i++){
		for (int j = i+1; j < n; j++){
			for (int k = j+1; k < n; k++){
				temp=arr[i]+arr[j]+arr[k];
			if(temp>m){break;}
			if(temp>max){max=temp;}
			}}}
	cout << max;
}