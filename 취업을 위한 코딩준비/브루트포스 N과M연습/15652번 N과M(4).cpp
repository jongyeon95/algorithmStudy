#include <iostream>
using namespace std;
int a[10];
bool b[10];


void go(int index, int N, int M, int start){
	if(index==M){
		for (int i = 0; i < M; i++)
		{
			cout << a[i];
			if (i!=M)
			{
				cout << " ";
			}
		}
		cout << "\n";
		return;

	}
	for (int j = start; j <= N; j++)
	{
		b[j]=true;
		a[index]=j;
		go(index+1,N,M,j);
		b[j]=false;

	}

	

}

int main(){

int N,M; //이 길이
cin >> N >> M;
go(0,N,M,1);
return 0;

}