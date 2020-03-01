#include <iostream>
using namespace std;

int main(){
	int testcase;
	scanf("%d",&testcase);
	for (int t = 1; t <= testcase; t++)
	{
		int result=0;
		int n;
		int temp;
		scanf("%d",&n);
		for (int i = 0; i < n; i++){
			scanf("%d",&temp);			
			if (i==0)
				result=temp;
			else{
				if(result==0||result==1){
				result+=temp;
				}
				else{
					if(temp==1||temp==0){
						result+=temp;
					}
					else{
						result*=temp;
					}
				}

			}
			
		}
		printf("#%d %d\n",t,result);
	}
}