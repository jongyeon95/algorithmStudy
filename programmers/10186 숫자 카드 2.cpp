#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[500000];
int n,m;
vector<pair<int,int>> v;
int binarySearch(int temp){
	int l=0;
	int r=v.size()-1;
	int mid=(l+r)/2;
	int cnt=0;
	while(r>=l){
		mid=(l+r)/2;
		if(v[mid].first<temp){
			l=mid+1;
		}
		else if(v[mid].first>temp){
			r=mid-1;
		}
		else{
			return v[mid].second;
		}
	}
	return 0;
}


int main(){
	cin.tie(0);
	cout.sync_with_stdio(false);
	cin >> n ;
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	sort(arr,arr+n);
	
	for(int i=0; i<n; i++){
		if(i==0){
			v.push_back({arr[i],1});
			continue;
		}
		if(arr[i]==v.back().first)
			v.back().second++;
		else
			v.push_back({arr[i],1});
	}
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		int temp;
		cin>>temp;
		cout<<binarySearch(temp)<<" ";
	}

}