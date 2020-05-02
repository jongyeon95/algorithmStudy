#include <iostream>
using namespace std;
 
int main()
{
    int n, MAP[50],ans=0,score[50]={0,};
    cin >> n;
    for(int i=0;i<n;i++)
       cin >> MAP[i];
    for(int i=0;i<n;i++)
    {
        long double angle = 1.0*-99999999999;
        for(int j=i+1; j<n; j++)
        {
            long double now = 1.0*(MAP[j]-MAP[i])/(j-i);
            if(now > angle){
                angle = now;
                score[i]++;
                score[j]++;
            }
        }
    }
 
    for(int i=0;i<n;i++)
        if(score[i]>ans)
            ans = score[i];
    cout << ans;
    return 0;
}