#include <iostream>
#include <algorithm>
using namespace std;

int total=0;

int main()
{
	int shorter[9];
	int flag[2];
	for(int i=0;i<9;i++){
		cin >> shorter[i];
		total+=shorter[i];
	}
	sort(shorter,shorter+9);
	for (int i = 0; i < 8; i++)
	{
		for (int j = i+1; j < 9; j++)
		{
			if((total-shorter[i]-shorter[j])==100){
				flag[0]=shorter[i];
				flag[1]=shorter[j];
				break;			
			}

		}
	}



	for (int i = 0; i < 9; i++)
	{
		if (shorter[i]!=flag[0] && shorter[i]!=flag[1])
		{
			cout << shorter[i] << endl;
		}
		
	}



}