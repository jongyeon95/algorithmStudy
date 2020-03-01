#include <iostream>
int main(){
    int testcase;
    scanf("%d",&testcase);
    for (int t = 1; t <= testcase; t++)
    {
        int n,k;
        int result;
        scanf("%d %d",&n,&k);
        printf("#%d",t);
       if(n%2==1)
           result=(k*n+1)*(n/2)+(k*n-k+2)/2;
        else
            result=(k*n+1)*(n/2);
        for (int i = 0; i < k; i++)
        {
            printf(" %d",result);
            if(n%2==1)
                result++;
        }
         
        printf("\n");
 
    }
}