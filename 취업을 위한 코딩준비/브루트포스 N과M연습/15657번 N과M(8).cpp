#include <iostream>
#include <algorithm>
using namespace std;
int a[10];
int num[10];
bool c[10];


void go(int index, int N, int M, int start){
	if (index==M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << num[a[i]];
			if (i!=M-1)
			{
				cout<<" ";
			}
		}
		cout << "\n";
		return;
	}
	for (int i = start; i < N; i++)
	{
		
		
		a[index]=i;
		go(index+1,N,M,i);
		

		/* code */
	}



}


int main(){
	int N,M;  // N개의 자연수 M개를 고른 수열
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> num[i];
	}
	sort(num,num+N);

	go(0,N,M,0);
	return 0;



}