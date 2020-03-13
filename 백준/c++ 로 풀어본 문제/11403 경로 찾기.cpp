#include <iostream>
#include <cstring>
using namespace std;
int n;
int arr[100][100];
bool visited[100];



void Init(){
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> arr[i][j];
		}
	}
}

void dfs(int start){

	for (int i = 0; i <n; ++i)
	{
		if(arr[start][i]==1 && !visited[i]){
			visited[i]=true;
			dfs(i);
		}
	}

}


int main(){
	cin.tie(0);
	cout.sync_with_stdio(false);
	Init();

	for(int i=0; i<n; i++){
		memset(visited,false,sizeof(visited));
		dfs(i);
		for (int j = 0; j < n; ++j)
		{
			if(visited[j])
				arr[i][j]=1;
		}

	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout<<arr[i][j]<<" ";
		}
		cout <<"\n";
	}


}
