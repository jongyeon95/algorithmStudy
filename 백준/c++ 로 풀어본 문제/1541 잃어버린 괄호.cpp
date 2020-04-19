#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int main() {
    int i, ans;
    int j = 0;
    int sum = 0;
    int temp = 0;
    int arr[25] = {0, };
    string s;
    cin >> s;

    int len = s.size();
    for (i = 0; i < len; i++) {
        if (s[i] == '-') {
            sum += temp;
            arr[j] = sum;
            j++;
            temp = 0;
            sum = 0;
        }
        else if (s[i] == '+') {
            sum += temp;
            temp = 0;
        }
        else {
            temp *= 10;
            temp += (s[i] - '0');
        }
    }

    sum += temp;
    arr[j] = sum;

    ans = arr[0];
    for (i = 1; i < 25; i++) {
        ans -= arr[i];
    }
    cout << ans;

    return 0;
}