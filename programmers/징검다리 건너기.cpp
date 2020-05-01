#include <string>
#include <vector>
using namespace std;
bool calc(int n, const vector<int>& stones, int k) {
    int now = 0;
    for (int i = 0; i < stones.size(); i++) {
        if (stones[i] - n <= 0)
            now++;
        else
            now = 0;
        if (now >= k)
            return false;
    }
    return true;
}
int solution(vector<int> stones, int k) {
    int left = 1;
    int right = 200000001;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (calc(mid, stones, k))
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left;
}
