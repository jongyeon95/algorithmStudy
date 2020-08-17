#include<iostream>
using namespace std;
int main() {
	int T, x;
	cin >> T;
	
	int N, n, distance, min_d, min_c;
	for(x=1; x<=T; x++) {
		cin >> N;
		min_d = 100001;
		for(n=0; n<N; n++) {
			cin >> distance;
			distance = abs(distance);
			if( distance < min_d ) {
				min_d = distance;
				min_c = 1;
				continue;
			}
			if( distance == min_d ) {
				min_c++;
			}
		}
		cout << "#" << x << " " << min_d << " " << min_c << endl;
	}
}