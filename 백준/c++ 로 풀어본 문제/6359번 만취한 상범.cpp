#include <iostream>
using namespace std;
int dp[101];
bool arr[101];
void saveDp(){
	for (int i = 0; i <=100; ++i)
	{
		arr[i]=true;
	}
	dp[0]=0;
	dp[1]=1;
	for (int i = 2; i <= 100; ++i)
	{
		int count=0;
		for (int j = i; j <= 100; j+=i)
		{
			arr[j]=!arr[j];
		}
		for (int j = 1; j <= i; ++j)
		{
			if(arr[j])
				count++;
		}
		dp[i]=count;
	}

}
int main(){
	saveDp();
	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; ++i)
	{
		int n;
		cin >> n;
		cout<<dp[n]<<endl;
	}

}