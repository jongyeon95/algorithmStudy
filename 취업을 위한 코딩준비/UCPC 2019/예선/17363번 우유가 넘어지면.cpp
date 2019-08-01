#include<iostream>
using namespace std;
int main(){
	int n,m;
	cin >> n >> m;
	char before[n][m];
	char after[m][n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> before[i][j];
			if (before[i][j]=='-'){
				before[i][j]='|';
			}
			else if(before[i][j]=='|'){
				before[i][j]='-';
			}
			else if(before[i][j]=='/'){
				before[i][j]='\\';
			}
			else if(before[i][j]=='\\'){
				before[i][j]='/';
			}
			else if(before[i][j]=='^'){
				before[i][j]='<';
			}
			else if(before[i][j]=='<'){
				before[i][j]='v';
			}
			else if(before[i][j]=='v'){
				before[i][j]='>';
			}
			else if(before[i][j]=='>'){
				before[i][j]='^';
			}
		}
	}
	int checkn=0;
	int checkm=0;

	for (int i = 0; i < n; i++)
	{
		for (int j = m-1; j >= 0; j--)
		{
			after[j][i]=before[checkn][checkm];
			checkm++;
			if(checkm==m){
				checkm=0;
				checkn++;
			}
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0;j <n; j++)
		{
			
			cout << after[i][j];
		}
		cout<< endl;
	}

}