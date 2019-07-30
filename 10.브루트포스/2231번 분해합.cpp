#include <iostream>
using namespace std;
int main(){
	int n;
	int count=0;
	cin >> n;
	int temp=n;
	int result=0;
	while(true){
		if(temp<10) break;
		temp/=10;
		count++;
	}
	for (int i = n-9*count; i < n; i++)
	{
		temp=i;
		int temp2=0;
		while(true){
			if (temp<10){break;}
			temp2+=temp%10;
			temp/=10;
		}
		temp2+=temp+i;
		if(temp2==n){result=i;
			break;}

	}
	cout << result;
}