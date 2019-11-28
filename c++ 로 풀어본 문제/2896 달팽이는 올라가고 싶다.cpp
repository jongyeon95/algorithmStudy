#include <iostream>
using namespace std;
 
int main(){
    int A, B, V, d;
    cin >> A >> B >> V;
    d = (V + A - 2 * B - 1)/ (A - B);
    cout << d << endl;
    return 0;
}