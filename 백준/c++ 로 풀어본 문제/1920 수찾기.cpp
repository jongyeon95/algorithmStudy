#include <iostream>
#include <algorithm>
using namespace std;
long long arrN[100001];
int n,m;
void sol(long long t){

	int mid;
	int s=0;
	int e=n-1;
	while(1){
		mid=(s+e)/2;
		if(!(e>=s)){
			cout <<0;
			break;
		}
		if(arrN[mid]==t){
			cout << 1;
			break;
		}

		if(arrN[mid]<t){
			s=mid+1;
		}
		else{
			e=mid-1;
		}
	}

}

int main(){
	cin.tie(0);
	cout.sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> arrN[i];
	}
	sort(arrN,arrN+n);
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		long long temp;
		cin >> temp;
		sol(temp);
		cout << "\n";
	}
	
}