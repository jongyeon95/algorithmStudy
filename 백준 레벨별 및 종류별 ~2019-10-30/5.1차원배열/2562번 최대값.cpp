#include <iostream>
#include <algorithm>
using namespace std;
int main(){
int arr[9];
int arr2[9];
int c=0;
for (int i = 0; i < 9; i++)
{
	cin >> arr[i];
	arr2[i]=arr[i];
}

sort(arr,arr+9);
for (int i = 0; i <9; i++)
{
	if (arr2[i]==arr[8])
	{
		break;
	}
	c++;
}
cout << arr[8] << endl << c+1;
}