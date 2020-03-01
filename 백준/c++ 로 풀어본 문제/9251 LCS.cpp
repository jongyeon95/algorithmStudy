#include <iostream>

#include <algorithm>
#include <string>
using namespace std;

int DP[1002][1002];  

int main() {
    string string1, string2;
    int i, j;

    cin >> string1 >> string2;

 
    for (i = 1; i <= string2.size(); ++i) {
        for (j = 1; j <= string1.size(); ++j) {
            if (string1.at(j - 1) == string2.at(i - 1)) DP[i][j] += DP[i - 1][j - 1] + 1;
            else DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
        }
    }


    cout << DP[i - 1][j - 1] << endl;

 

    return 0;

}