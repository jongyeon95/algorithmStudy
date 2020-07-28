#include <iostream>
using namespace std;

long long arr[68]={1,1,2,4,};

int main(){

	for(int i=4; i<=67; i++){
		arr[i]=arr[i-1]+arr[i-2]+arr[i-3]+arr[i-4];
	}

	int test_case;
	cin >> test_case;
	for (int i = 0; i < test_case; ++i)
	{
		int temp;
		cin >> temp;
		cout<<arr[temp]<<"\n";
	}
	
	
}