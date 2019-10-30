#include <iostream>
using namespace std;
int a[10];

void go(int i,int start, int M , int N){
if (i==N)
{
	for(int j=0;j<N;j++){
		cout << a[j];
		if (j!=N-1) cout<<' ';
	}
	cout << "\n";
	return;
}

for (int k =start; k <= M; k++)
{
	
	a[i]=k;
	go(i+1,k+1,M,N);


	
}



}

int main(){
int M,N;
cin >> M >> N;
go(0,1,M,N);

}