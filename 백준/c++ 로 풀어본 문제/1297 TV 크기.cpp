#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int L, a, b;
    double c, t1, t2;
    cin >> L >> a >> b;
    c = sqrt(a * a + b * b);
    t1 = a * L / c;
    t2 = b * L / c;
 	cout<<(int)t1<<" "<<(int)t2;
   
    return 0;
}