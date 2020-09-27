#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int n;
	int arr1[50];
	int arr2[50];
	int answer=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin >> arr1[i];
	}
	for(int i=0;i<n;i++){
		cin >> arr2[i];
	}

	sort(arr1,arr1+n);
	sort(arr2,arr2+n,greater<>());

	for(int i=0; i<n; i++){
		answer+=arr1[i]*arr2[i];
	}

	cout<<answer;
}