#include <iostream>
using namespace std;
int tree[100001];
int t[100001];
int n,ans;
int cmp = 100000000;
int m = 100000000;
int gcd(int a, int b)
{
    if (b == 0) { return a; }
    return gcd(b, a%b);
}
int main() {
    
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> tree[i];
 
        if (i >= 2)
        {
            t[i] = tree[i] - tree[i - 1]; 
            cmp = gcd(t[i], t[i - 1]);
        }
    
        if (m > cmp)
            m = cmp;
    }
    for (int i = 2; i <= n; i++)
    {
        ans += t[i] / m-1;
    }
    cout << ans << '\n';
}


