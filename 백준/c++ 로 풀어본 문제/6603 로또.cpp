#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int arr[13];
bool checked[13];
int n;

void dfs(int start,vector<int> v){

	if(v.size()==6){
		for (int i = 0; i < v.size(); ++i)
		{
			cout<<v[i]<<" ";
		}
		cout<<"\n";
		return;
	}
	for(int i=start; i<n;i++){
		if(!checked[i]){
			checked[i]=true;
			v.push_back(arr[i]);
			dfs(i,v);
			v.pop_back();
			checked[i]=false;
		}
	}
}

int main(){
	cin.tie(0);
	cout.sync_with_stdio(false);
	while(1){
		cin >> n;
		if(n==0)
			break;
		memset(arr,0,sizeof(arr));
		memset(checked,false,sizeof(checked));
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}
		vector<int> v;
		dfs(0,v);
		
		
		cout << "\n";

	}
}