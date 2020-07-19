#include<iostream>
#include<cstring>

using namespace std;

int num[]={2,3,5,7,11};

int main(int argc, char** argv)
{
    int result[5];
	int test_case;
	int T;
	scanf("%d",&T);
	for(test_case = 1; test_case <= T; ++test_case)
	{
        memset(result,0,sizeof(result));
        int n;
        scanf("%d",&n);
        int flag=0;

        while(flag<5){
        	if(n%num[flag]==0){
                n/=num[flag];
            	result[flag]++;
            }
            else
                flag++;
        }

        printf("#%d %d %d %d %d %d\n",test_case,result[0],result[1],result[2],result[3],result[4]);
	}
	return 0;
}