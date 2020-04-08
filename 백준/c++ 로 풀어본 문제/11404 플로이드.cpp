#include <iostream>
using namespace std;
int main(){
	cin.tie(0);
	cout.sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	int map[n+1][n+1];
	//init
	for (int i = 1; i < n+1; ++i)
		for (int j = 1; j < n+1; ++j)
			map[i][j]=987654321;
	
	//input
	for (int i = 0; i < m; ++i)
	{
		int a,b,c;
		cin >> a >> b >> c;
		if(map[a][b]>c)
			map[a][b]=c;
	}
	for (int i = 1; i < n+1; ++i)
	{
		for (int j = 1; j < n+1; ++j)
		{
			for (int k = 1; k < n+1; ++k)
			{
				if(j==k||i==k||j==i)
					continue;
				if(map[i][k]+map[j][i]<map[j][k])
					map[j][k]=map[i][k]+map[j][i];
			}
		}
	}

	for (int i = 1; i < n+1; ++i)
	{
		for (int j = 1; j < n+1; ++j)
		{
			if(map[i][j]==987654321)
				cout<<"0 ";
			else
				cout<<map[i][j]<<" ";
		}
		cout<<"\n";
	}


}