#include <iostream>
using namespace std;
int dp[15];
int arr[15][2];
bool check=true;


int mian(){
	
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i][0] >> arr[i][1];
	}
	for (int i = 0; i < N; i++)
	{
		check=true;
		int j=i;
		int temp=0;
		while(check){
			if (j>N)
			{
				check=false;
				
			}


		}
	}



}