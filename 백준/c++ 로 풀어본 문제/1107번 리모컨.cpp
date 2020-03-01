#include<iostream>
#include<string>
#include<algorithm>
 
using namespace std;
 
int brokenBtn[10];
  int N, M;
 
bool possible(int k) {
    if (k == 0)
        return brokenBtn[0] ? false : true;
    while (k) {
        if (brokenBtn[k % 10] == 1) {
            return false;
        }
        k /= 10;
    }
    
    return true;
}
 
int find(int N) {
    int result = abs(N - 100);
    int temp;
    int INF = N * 2 - 100;
    if (INF < 100)
        INF = 100;
    for (int i = 0; i <= INF; i++) {
        temp = to_string(i).length() + abs(i-N);
        if (possible(i)) {
            result = min(temp, result);
        }
    }
 
    return result;
}
 
int main(void)
{
    
    int temp;
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> temp;
        brokenBtn[temp] = 1;
    }
    cout << find(N) << endl;
    return 0;
}
