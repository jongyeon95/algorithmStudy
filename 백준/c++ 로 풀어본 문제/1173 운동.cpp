#include <iostream>
using namespace std; 
int main(){
	int N,m,M,T,R;
	cin >> N >> m >> M >> T >> R;
	int heartBeat=m;
	int result=0;
	if(m+T>M){
		cout<<-1;
		return 0;
	}
	while(N>0){
		if(heartBeat+T>M){
			if(heartBeat-R<m){
				heartBeat=m;
			}
			else
				heartBeat-=R;
		}
		else{
			heartBeat+=T;
			N--;
		}
		result++;
	}
	cout << result;
}