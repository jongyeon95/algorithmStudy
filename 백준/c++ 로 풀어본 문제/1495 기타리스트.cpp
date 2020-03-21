#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int sound[101][1001];
int arr[101];
int n , m, s;
int solve(int flag, int vol){
	if(vol<0||vol>m)
		return -2;
	if(sound[flag][vol]!=-1)
		return sound[flag][vol];
	if(flag==n)
		return sound[flag][vol]=vol;
	sound[flag][vol]=max(solve(flag+1,vol+arr[flag])
		,solve(flag+1,vol-arr[flag]));
	return sound[flag][vol];

}

int main(){
	cin >> n >> s >> m;
	memset(arr,-1,sizeof(arr));
	memset(sound,-1,sizeof(sound));
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	int result=solve(0,s);
	if (result==-2)
	{
		cout << -1;
	}
	else
		cout <<result;
}