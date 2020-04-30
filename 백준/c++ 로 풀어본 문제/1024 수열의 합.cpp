#include<iostream>
using namespace std;
 
int N, L;
 
void calc() {
    int count, sum, i, flag;
    count=0;
    sum=0;
    i=L-1;
    flag=0;
    while (sum != N) {
        sum = 0;
        count = 0;
        i++;
        if (i > 100) {
            flag = 1;
            break;
        }
        for (int t = 0; t < i; t++) {
            sum += count++;
        }
        while (sum < N) {
            sum += i;
            count++;
        }
    }
    if (flag) {
        cout << "-1";
    }
    else
        for (i; i > 0; i--)
            cout << count - i << " ";
}
 
int main() {
    cin >> N >> L;
    calc();
}
