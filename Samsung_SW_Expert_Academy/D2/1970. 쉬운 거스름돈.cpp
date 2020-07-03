#include<stdio.h>
 
int main()
{
    int test_case;
    int T;
    scanf("%d",&T);
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int money[]={50000,10000,5000,1000,500,100,50,10};
        int num;
        scanf("%d",&num);
        printf("#%d\n",test_case);
        for(int i=0; i<8; i++){
            printf("%d ",num/money[i]);
            num%=money[i];
        }
        printf("\n");
 
    }
    return 0;
}