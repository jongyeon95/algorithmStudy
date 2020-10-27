#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
int main(){
	int n;
	cin >> n;
	int arr[n];
	int result[n];
	memset(result,0,sizeof(result));
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	stack<int> s;
	for(int i=n-1; i>=0; i--){
		if(i==n-1){
			s.push(n-1);
		}
		else{
			while(!s.empty()){
				if(arr[i]>arr[s.top()]){
					result[s.top()]=i+1;
					s.pop();
				}
				else{
					break;
				}
			}
			s.push(i);
		}
	}
	for(int i=0; i<n; i++){
		cout<<result[i]<<" ";
	}

}