#include<iostream>
#include<algorithm>
using namespace std;
 
int main() {
 
    
    int N;
    cin >> N;
    int Num = 666;
    int count = 1;
    while (1) {
        if (N == count)
            break;
        Num++;
        int copy_Num = Num;
        int flag = 0;
        while (copy_Num) {
            int temp = copy_Num % 10;
            if (temp == 6)
                flag++;
            else if (flag < 3)
                flag = 0;
            copy_Num /= 10;
        }
 
        if (flag >= 3)
            count++;
    }
 
    cout << Num;
 
    return 0;
}