#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 
int main() {
	ios::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL); 
	int tc; 
	cin >> tc; 
	for (int t = 1; t <= tc; t++) {
		int N, T, D, start = 0;
		cin >> N;
		vector<pair<int, int>> homework;

		for (int i = 0; i < N; i++) {
			int a,b;
			cin >> a >> b;
			homework.push_back({b,a});
			
		}

		sort(homework.begin(), homework.end());
		start = homework.back().first - homework.back().second + 1;
		homework.pop_back(); 
		while (!homework.empty()) {
			int end = homework.back().first; 
			int st = end - homework.back().second + 1; 
			homework.pop_back();

			if (start <= end) { 
				start = st - ( end - start +1);
			}
			else {
				start = st ;
			}
		}
		cout << "#" << t << " " << start - 1<<"\n";
	}

}
