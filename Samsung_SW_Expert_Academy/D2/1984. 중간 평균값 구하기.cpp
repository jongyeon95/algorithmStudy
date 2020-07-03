#include<iostream>
using namespace std;
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int max=-1;
        int min=10001;
        float result=0;
        int n;

        for(int i=0; i<10; i++){
        	scanf("%d",&n);
            if(n>max)
                max=n;
            if(n<min)
                min=n;
            result+=n;
        }

        result-=min+max;
        result/=8;

        //int 강제형변환을 통해 소수값 구하기
        //반올림
        if(result-(int)result>=0.5){
        	result+=1;
        }
        printf("#%d %d\n",test_case,(int)result);
	}
	return 0;
}