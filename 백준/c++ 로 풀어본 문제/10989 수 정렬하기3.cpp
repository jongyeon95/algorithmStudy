#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
	int num[10001];
	int n;
	cin>>n;
	memset(num, 0, sizeof(num));
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		num[temp]++;
	}
	for(int i=1;i<10001;i++){
		if(num[i]>0){
			for (int j = 0; j < num[i]; j++)
			{
				cout<<i<<"\n";
			}
		}
	}
}