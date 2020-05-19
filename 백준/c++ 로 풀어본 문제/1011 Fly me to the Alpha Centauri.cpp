#include<iostream>
#include<cstdio>
using namespace std;

int warp(int dist) {
	long long n, minN, powN, maxN, warpCount= 0;
	for(n=1;;n++){
		powN = n*n;
		minN = powN - n + 1;
		maxN = powN + 1 + n - 1;
		if(minN<=dist && dist<=maxN){
			if(minN<=dist && dist<=powN) warpCount = (n<<1) - 1;
			else warpCount = n<<1;
			break;
		}
	}
	return warpCount;
}

int main() {
	int t, x, y, dist; 
	cin >> t;
	while (t--) {
		cin >> x >> y;
		dist = y - x;
		cout<<warp(dist) << endl;
	}
}
