#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<vector<int>> v;
bool visited[50];
int n;
int delNode;

void delNodes(int node){
	if(!visited[node]){
		visited[node]=true;
		for (int i = 0; i < v[node].size(); ++i)
		{
			delNodes(v[node][i]);
		}
	}

}


int main(){
	cin >> n;
	int result=0;
	memset(visited,false,sizeof(visited));
	v.resize(n);
	for (int i = 0; i < n; ++i)
	{
		int node;
		cin >> node;
		if(node!=-1){
			v[node].push_back(i);
		}

	}
	cin>>delNode;
	delNodes(delNode);
	for (int i = 0; i < n; ++i)
	{
		if(!visited[i]){
			int cnt=0;
			for (int j = 0; j < v[i].size(); ++j)
			{
				if(!visited[v[i][j]]){
					cnt++;
				}
			}
			if(cnt==0)
				result++;
		}
	}
	cout<<result;
}