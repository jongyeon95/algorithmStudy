#include <iostream>
using namespace std;

int main(){
    int  testcase;
    scanf("%d",&testcase);
    for(int t=1; t <= testcase; t++){
        int n,x;
        scanf("%d %d",&n,&x);
        
        printf("#%d ", t);
        
        if(x!=1&&x!=2*n-1){
           printf("1\n");
        }else{
         printf("0\n");
        }
    }
       

}