#include <iostream>
#include <cstring>
using namespace std;
int arr[1004];

int Cansee(int num){
	int temp=0;
	int returnNum=0;
	for (int i = num-2; i < num+3; ++i)
	{
		if(i==num)
			continue;
		if(arr[i]>temp)
			temp=arr[i];
	}
	returnNum=arr[num]-temp;
	if(returnNum<=0)
		return 0;
	return returnNum;
}

int main(){
	cin.tie(0);
	cout.sync_with_stdio(false);
	
	for (int t = 1; t <= 10; ++t)
	{
		int n;
		cin >> n;
		int result=0;
		memset(arr,0,sizeof(arr));
		for (int i = 2; i <n+2; ++i)
		{
			cin >> arr[i];
		}
		for (int i = 2; i <n+2; ++i)
		{
			result+=Cansee(i);
		}
		cout <<"#"<<t<<" "<<result<<"\n";
	}
}