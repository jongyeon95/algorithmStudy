#include <iostream>
using namespace std;

int main()
{
    int N,cnt,a, b, c;
    cnt = 99;
    cin >> N;
    if (N < 100)
    {
       cout << N;
    }
    else
    {
        for (int i = 100; i <= N; i++)
        {
            a = i / 100;        // 100의 자리
            b = (i / 10) % 10;    // 10의 자리
            c = i % 10;            // 1의 자리
 
            if ((a - b) == (b - c)) // 100 10 1 의 자리의 차이가 같으면 등차 
            {
                cnt++;
            }
        }
       cout << cnt;
    }
    return 0;
}

