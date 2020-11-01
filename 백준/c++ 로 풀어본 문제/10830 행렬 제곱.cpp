#include <iostream>
using namespace std;
int main(){
	long long n,m;
	cin >> n >> m;
	long long answer[n][n];
	long long multi[n][n];
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> multi[i][j];
			answer[i][j]=0;
		}
		answer[i][i]=1;
	}
	
	while(m>0){
		
		long long tempArr[n][n];
		if(m%2==1){
			for(int i=0; i<n; i++){
				for(int j=0; j<n; j++){
					tempArr[i][j]=0;
					for(int k=0; k<n; k++){
						tempArr[i][j]+=answer[i][k]*multi[k][j];
					}
				}
			}

			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < n; ++j)
				{
					answer[i][j]=tempArr[i][j]%1000;
				}
			}
		}
		
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				tempArr[i][j]=0;
				for(int k=0; k<n; k++){
					tempArr[i][j]+=multi[i][k]*multi[k][j];
				}
			}
		}
		
		
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				multi[i][j]=tempArr[i][j]%1000;
			}
		}

		
		m/=2;
	}


	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout<<answer[i][j]<<" ";
		}
		cout<<"\n";
	}

}