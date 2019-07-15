#include <iostream>
using namespace std;
 
int main() {
    int h, m;
    cin >> h >> m;
    h = m - 45 < 0 ? h - 1 : h;
    cout << (h < 0 ? 23 : h) << " " << (m - 45 < 0 ? m + 15 : m - 45);
    return 0;
}
