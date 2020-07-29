#include <iostream>
 using namespace std;
long long  ans;
long long  s, t, a, b;
int testcase;

int main()
{
    cin >> testcase;
    for(int tc=1; tc<=testcase; ++tc)
    {
        ans=0;
        cin >> s>> t>>a>>b;
     
        if(b==1)
        {
            if((t-s)%a ==0)
            {
                ans = (t-s)/a;
            }
            else ans = -1;
        }
        else
        {
            while(t>s)
            {
                if(t%b==0 && t/b>=s) 
                {
                    t= t/b;
                    ans++;  
                }
                else
                {
                    t-=a;
                    ans++;
                }
            }
            if(t!=s)
                ans = -1;
        }
        cout<<"#"<<tc<<" "<<ans<<"\n";
   
    }
    return 0;
}