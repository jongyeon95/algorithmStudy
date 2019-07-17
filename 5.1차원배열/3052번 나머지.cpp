#include <iostream>
using namespace std;
int main(){
	int remainder[10]={10,10,10,10,10,10,10,10,10,10};
	int c=0;
	int temp=0;
	for (int i = 0; i < 10; i++)
	{
		
		bool check=true;
		int j=0;
		cin >> temp;
		while(check){
			if(remainder[j]==10){
				remainder[j]=temp%42;
				c++;
				check=false;
			}
			if (remainder[j]==temp%42)
			{
				check=false;
			}
			j++;
		}
	}
	cout << c;

}