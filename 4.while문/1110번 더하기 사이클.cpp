#include <iostream>
using namespace std;

int main(){
    int a;
	int c=0;
	int temp;
	cin >> a;
	temp=a;
	while(true){
		temp=(temp%10)*10+(temp/10+temp%10)%10;
		c++;
		if(temp==a) break;
		
	}
	cout << c;

}