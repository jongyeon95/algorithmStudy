#include <iostream>
#include <queue>
using namespace std;

int main(){
	priority_queue<long long, vector<long long>,greater<long long>> pq;
	int n,m;
	cin >> n >> m;
	for(int i=0; i<n; i++){
		int temp;
		cin >> temp;
		pq.push(temp);
	}
	while(m--){
		long long a, b;
		a=pq.top();
		pq.pop();
		b=pq.top();
		pq.pop();
		long long temp=a+b;
		pq.push(temp);
		pq.push(temp);
	}

	long long result=0;
	while(!pq.empty()){
		result+=pq.top();
		pq.pop();
	}
	cout<<result;


}