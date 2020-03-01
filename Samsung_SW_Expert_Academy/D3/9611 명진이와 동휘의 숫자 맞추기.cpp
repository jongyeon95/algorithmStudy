#include <iostream>
#include <cstring>
using namespace std;

int number[10];

int main(){
	int testcase;
	cin >> testcase;
	for (int t = 1; t <= testcase; ++t)
	{
		int n;
		memset(number,0,sizeof(number));
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			int temp[4];
			string s;
			for (int j = 0; j < 4; ++j)
			{
				cin >> temp[j];
			}
			cin >> s;
			if(s=="NO"){
				for (int j = 0; j < 4; ++j)
				{
					number[temp[j]]=1;
				}
			}
			else if(s=="YES"){
				for (int j = 0; j < 4; ++j)
				{
					if(number[temp[j]]!=1)
						number[temp[j]]=2;
				}
				for (int  j = 0; j < 10; ++j)
				{
					bool check=true;
					for(int k=0; k<4; k++){
						if(j==temp[k])
							check=false;
					}
					if (check)
					{
						number[j]=1;
					}
				}

			}

		}
		printf("#%d ",t );
		bool check=false;
			for (int j = 0; j <10; ++j)
			{
				if(number[j]==2){
					printf("%d\n",j);
					check=true;
				}
			}
			if(!check){
				for (int j = 0; j <10; ++j){
					if(number[j]==0)
						printf("%d\n",j);
					}
			}
	}

}