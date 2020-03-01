#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int main(){
	int testcase;
	int n,m;
	scanf("%d",&testcase);
	for (int t = 1; t<= testcase; ++t)
	{
		scanf("%d %d",&n,&m);
		int result=0;
		int nfee[n];
		int car[m];
		for (int ni = 0; ni < n; ++ni)
		{
				int temp;
				scanf("%d",&temp);
				nfee[ni]=temp;
		}
		for (int mi = 0; mi < m; ++mi)
		{
				int temp;
				scanf("%d",&temp);
				car[mi]=temp;
		}
		int Isfree=n;
		int parkzone[n];
		queue<int> bufferCar;
		memset(parkzone,0,sizeof(parkzone));
		for (int i = 0; i < 2*m; ++i)
		{
			int inout;
			scanf("%d",&inout);
			if(inout>0)
			{
				if(Isfree>0){
					for (int index = 0; index < n; ++index){
						if(parkzone[index]==0){
						parkzone[index]=inout;
						Isfree--;
						break;
						}
					}
				}
				else{
					bufferCar.push(inout);
				}
			}
			else if(inout<0){
				for (int index = 0; index < n; ++index)
				{
					if(parkzone[index]==inout*-1){
						parkzone[index]=0;
						result+=(car[(inout*-1)-1]*nfee[index]);
						Isfree++;
						break;
					}

				}

				if(bufferCar.size()>0){
					for (int index = 0; index < n; ++index){
						if(parkzone[index]==0){
						int temp=bufferCar.front();
						bufferCar.pop();
						parkzone[index]=temp;
						Isfree--;
						break;
						}
					}
				}


			}
		}
		printf("#%d %d\n",t,result);

	}
}