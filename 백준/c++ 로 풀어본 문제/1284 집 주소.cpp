#include <iostream>
#include <string>
using namespace std;

int main() {
	
	string N;
	
	while(1) {
		cin >> N;
		if(N=="0") return 0; 
		
		int sum = 0;
		for(int i=0; i<N.length(); i++) {
			if(N[i]=='1') sum += 2;
			else if(N[i]=='0') sum += 4;
			else sum += 3;
			sum++; 
		}
		cout << sum+1 << "\n";
	}
	
	return 0;
}