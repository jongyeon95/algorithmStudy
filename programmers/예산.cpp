#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> budgets, int M) {
    long long sum=0;
    sort(budgets.begin(), budgets.end());
    for (int i = 0; i < budgets.size(); i++) {
        sum += budgets[i];
    }
    if (sum < M) return *(budgets.end() - 1);
    long long avg = sum / budgets.size();
    long long sum1 = 0;
    int size = budgets.size();
    long long avg1 = M / size;
    for (int i = 0; i < budgets.size(); i++) {
        if (budgets[i] > avg1) return avg1;
        sum1 += budgets[i];
        size--;
        avg1 = (M - sum1) / size;
    }
}