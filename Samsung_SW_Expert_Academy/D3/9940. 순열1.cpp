#include<iostream>
#include<cstring>
 
using namespace std;
 
int main(int argc, char** argv)
{
    bool arr[100001];
    int test_case;
    int T;
    scanf("%d",&T);
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int n,temp;
        string result="Yes";
        scanf("%d",&n);
        memset(arr,false,sizeof(arr)); //arr 배열 초기화
        
        for(int i=0; i<n; i++){
            scanf("%d",&temp);
            if(arr[temp])
                result="No";
            else
                arr[temp]=true;
        }

        printf("#%d %s\n",test_case,result.c_str()); //c_str()은 string 자료형을 %s로 출력가능하게 만드는 함수
    }
    return 0;
}