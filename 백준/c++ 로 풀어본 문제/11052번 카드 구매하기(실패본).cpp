#include <iostream>
using namespace std;

int sol(int a, int b){
	if(a>=b) return a;
	else return b;
}

int main(){
int N;
int P[1001];
int DP[1001];
P[0]=0;
DP[0]=0;
cin >> N;

for (int i = 1; i <= N; i++){
	cin >> P[i];
}


for (int i = 1; i<= N; i++){
	for (int j = 1; j<=i; j++){
		DP[i]=sol(DP[i-j]+P[j],DP[i]);
	}
}
	
cout << DP[N] << "\n";

}