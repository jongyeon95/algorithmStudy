#include <iostream>
#include <cstring>
#include <cstdio>
 
using namespace std;
 
int main()
{
    int N, sum, count;
    char M[80];
    scanf("%d", &N);
    for (int i=0; i<N; i++)
    {
        scanf("%s", M);
        sum = 0;
        count = 0;
        for (int j = 0; j<strlen(M); j++)
        {
            if (M[j] == 'O')
            {
                count++;
            }
            if(M[j] == 'X' || j == strlen(M)-1)
            {
                sum += count * (count + 1) / 2;
                count = 0;
            }
        }
        printf("%d\n", sum);
    }
}
