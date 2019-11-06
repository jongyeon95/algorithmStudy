#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
	double Average=0;
	vector<int> v;
	vector<int> mode;
	int arr[8001];
	memset(arr,0,sizeof(arr));
	int n;
	int temp;
	int max=0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		v.push_back(temp);
		arr[temp+4000]++;
		if(arr[temp+4000]>max){
			max=arr[temp+4000];
		}
		Average+=temp;
	}

	for (int i = 0; i < 8001; i++)
	{
		if(arr[i]==max)
			mode.push_back(i-4000);
	}

	sort(v.begin(),v.end());
	sort(mode.begin(),mode.end());

	printf("%.0f\n",Average/n);
	printf("%d\n",v[(v.size()-1)/2]);
	if(mode.size()>1)
		printf("%d\n",mode[1]);
	else
		printf("%d\n",mode[0]);
	printf("%d\n",v[v.size()-1]-v[0]);
	




}
