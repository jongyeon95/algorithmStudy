#include<stdio.h>
#include<math.h>
#include<vector>
#include<string>
using namespace std;
int p[2000001];
vector<int> v;
void sieve();
int isPal(int);
int main()
{
    sieve();
    int N;
    scanf("%d", &N);
    for (int i = 2; i <= 2000000; ++i)
        if (!p[i] && isPal(i)&&i>=N){
            printf("%d", i);
            return 0;
        }
}
int isPal(int n)
{
    string s = to_string(n);
    int i = 0;
    int j = s.length() - 1;
    while (i <= j)
    {
        if (s[i] != s[j])
            return 0;
        ++i;
        --j;
    }
    return 1;
 
}
void sieve()
{
    int s = sqrt(2000000);
    for (int i = 2; i <= s; ++i)
    {    
        if(!p[i])
        for (int j = i * 2; j <= 2000000; j += i)
        {
            p[j] = 1;
        }
    }
}
