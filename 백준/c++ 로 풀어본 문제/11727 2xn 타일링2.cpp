#include <iostream>
using namespace std;
int main(){
	int arr[1001]={0,1,3};
	int n;
	cin >> n;
	if(arr[n]==0){
		for (int i = 3; i <=n; i++)
		{
			arr[i]=arr[i-1]+2*arr[i-2];
			arr[i]%=10007;
		}
	}
	cout << arr[n];

}