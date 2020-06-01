#include <iostream>
#include <cstring>
using namespace std;
int arr[100001];
int reslutArr[100001];

void init(){
	memset(arr,0,sizeof(arr));
	for (int i = 1; i <=100000; ++i)
	{
		for(int j=i; j<=100000; j+=i){
			arr[j]++;
		}
	}
	int maxNum=2;
	int flag=2;
	for (int i = 2; i <=100000; ++i)
	{
		if(arr[i]<maxNum){
			arr[i]=flag;
		}
		else if(arr[i]==maxNum){
			flag=i;
			arr[i]=i;
		}
		else{
			maxNum=arr[i];
			flag=i;
			arr[i]=i;
		}
	}

}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int testcase;
	cin >> testcase;
	init();
	for (int t = 1; t <= testcase; ++t)
	{
		int n;
		cin >> n;
		cout<<"#"<<t<<" "<<arr[n]<<"\n";
	}
}