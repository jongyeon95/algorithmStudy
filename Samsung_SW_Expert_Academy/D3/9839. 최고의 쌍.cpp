#include<iostream>
#include<string>
using namespace std;
int main(int argc, char** argv)
{
	int test_case,T;
	scanf("%d",&T);
    int arr[1000];
    int result,n;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        result=-1;
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        	scanf("%d",&arr[i]);
        
        for(int i=0; i<n-1; i++){
        	for(int j=i+1; j<n; j++){
                int temp=arr[i]*arr[j];
                
                //result 값이 이미 temp보다 크다면 할 필요가 없음
                if(temp > result){
                    bool check=true;
                    int ttemp=temp;

                    while(ttemp/10>0){
                        if(ttemp%10-1!=(ttemp/10)%10){
                        	check=false;
                            break;
                        }
                        ttemp/=10;
                    }
                    if(check)
                        result=temp;
                }
            }
        }
        
        printf("#%d %d\n",test_case,result);
	}
	return 0;
}