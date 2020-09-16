#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n, cursor;
long long arr[1000001];
queue<long long> que;
void init()
{
    while (!que.empty())
    {
        cursor++;
        long long now = que.front();
        que.pop();
        arr[cursor] = now;
 
        for (long long i = 0; i < now % 10; i++)
        {
            long long next = now * 10 + i;
            que.push(next);
        }
    }
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    for (long long i = 1; i < 10; i++)
    {
        que.push(i);
    }
    init();
    cin >> n;
    if (n != 0 && arr[n] == 0)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << arr[n];
    }
    return 0;
}
