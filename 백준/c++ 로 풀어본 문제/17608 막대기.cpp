#include <iostream>
using namespace std;
int main(){
	int n;
	int max=0;
	int result=0;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	for (int i = n-1; i >=0 ; i--)
	{
		if(arr[i]>max){
			result++;
			max=arr[i];
		}
	}

	cout << result;

}