#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{    
        int N;
        cin >> N;
        vector<int> v(N);
        for (int i = 0; i < N; i++)
                 cin >> v[i];
        int result = 0;
        sort(v.begin(), v.end());
        do
        {
                 int temp = 0;
                 for (int i = 0; i < v.size() - 1; i++)
                         temp += abs(v[i] - v[i + 1]);
                 result = max(result, temp);
        } while (next_permutation(v.begin(), v.end()));


        cout << result;

        return 0;

}