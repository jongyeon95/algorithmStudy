#include <iostream>
using namespace std;

int main() {
    int a,b,c;
    int greatest;
    while(1)
    {
        cin >> a >> b >> c;
        if(a == 0)
            break;
        if(max(a,b) == a)
            if(max(a,c) == a)
            {
                if(a*a == b*b + c*c)
                    cout << "right" << '\n';
                else
                    cout << "wrong" << '\n';
            }
            else
            {
                if(c*c == a*a + b*b)
                    cout << "right" << '\n';
                else
                    cout << "wrong" << '\n';
            }
        else
            if(max(b,c) == b)
            {
                if(b*b == a*a + c*c)
                    cout << "right" << '\n';
                else
                    cout << "wrong" << '\n';
            }
            else
            {
                if(c*c == a*a + b*b)
                    cout << "right" << '\n';
                else
                    cout << "wrong" << '\n';
            }
    }
}