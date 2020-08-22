#include<iostream>
#include<algorithm>
 
using namespace std;
 
int arr[500001];
 
int findH(int N) {
    int maxN = 0;
 
    for (int i = 1; i <= N; i++) 
        if (arr[N - i] >= i) 
            maxN = i;   
    return maxN;
}
 
 
int main() {
    cin.tie(0);
	cout.sync_with_stdio(false); 
    int T, N;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cin >> N;
        for (int j = 0; j < N; j++) {
            cin >> arr[j];
        }
        sort(arr, arr + N);
        cout << "#" << i << " " << findH(N) << "\n";
    }
    return 0;
}