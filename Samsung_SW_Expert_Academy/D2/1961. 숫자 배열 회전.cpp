#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	scanf("%d",&T);
	int map[7][7];
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int n;
        scanf("%d",&n);
        
        //입력
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                scanf("%d",&map[i][j]);
            }
        }

        printf("#%d\n",test_case);

        for(int i=0; i<n; i++){
            //90
            for(int j = 0; j < n; j++)
                printf("%d",map[n-j-1][i]);
            printf(" ");

            //180
            for(int j = 0; j < n; j++)
                printf("%d",map[n-i-1][n-j-1]);
            printf(" ");

            //270
            for(int j = 0; j < n; j++)
                printf("%d",map[j][n-1-i]);	
            printf("\n");
        }

    }
    return 0;
}