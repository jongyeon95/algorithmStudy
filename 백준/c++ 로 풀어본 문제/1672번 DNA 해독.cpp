#include <iostream>

#include <string>

#include <cstring>

using namespace std;

 

int N;

string change = "ACAGCGTAATCGGAGT";

 

char func(char a, char b)

{

        int idx = (a == 'A' ? 0 : a == 'G' ? 1 : a == 'C' ? 2 : 3);

        int idx2 = (b == 'A' ? 0 : b == 'G' ? 1 : b == 'C' ? 2 : 3);

 

        return change[idx * 4 + idx2];

}

 

int main(void)

{

       
        string s;

        cin >> N >> s;

 

        for (int i = s.length() - 2; i >= 0; i--)

                 s[i] = func(s[i], s[i + 1]);

 

        cout << s[0] << "\n";

        return 0;

}