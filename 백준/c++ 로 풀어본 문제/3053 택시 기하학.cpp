#include <iostream>
#include <cmath>
#define PI 3.1415926535897932
using namespace std;

int main() {
    long double R;
    cin>>R;
    cout<<fixed;
    cout.precision(6);
    cout<<powl(R, 2) * PI<<'\n';
    cout<<powl(R, 2) * 2<<'\n';
}