#include <iostream>
#include <cstring>
using namespace std;
int main(){
	int n;
	int plasticNum[9];
	memset(plasticNum,0,sizeof(plasticNum)); // 0으로 배열 초기화  
	cin >> n;
	if(n==0){
		cout<<1;
		return 0;
	}
	while(n>0){ //9이면 6으로 빠끄 
		int temp;
		temp=n%10;
		if (temp==9)
			temp=6;
		plasticNum[temp]++;
		n/=10;
	}

	if (plasticNum[6]%2==1)
		plasticNum[6]=plasticNum[6]/2+1;
	else
		plasticNum[6]/=2;
	int max=0;
	for (int i = 0; i < 9; i++)
	{
		if(plasticNum[i]>=max)
			max=plasticNum[i];
	}
	
		cout << max;

}