#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int main(){
	int computer,network;
	cin >> computer >> network;
	int arr[computer+1][computer+1];
	bool check[computer+1];
	memset(arr,0,sizeof(arr));
	memset(check,false,sizeof(check));
	for (int i = 0; i < network; ++i)
	{
		int a,b;
		cin >> a >> b;
		arr[a][b]=1;
		arr[b][a]=1;
	}
	int result=0;
	queue<int> q;
	check[1]=true;
	for (int i = 1; i < computer+1; ++i)
	{
		if(arr[1][i]==1){
			check[i]=true;
			q.push(i);
			result++;
		}
	}
	
	while(!q.empty()){
		int temp=q.front();
		q.pop();
		for (int i = 1; i < computer+1; ++i)
		{
			if(arr[temp][i]==1&&!check[i]){
				check[i]=true;
				result++;
				q.push(i);
			}
		}
	}


	cout << result;




	
	

}