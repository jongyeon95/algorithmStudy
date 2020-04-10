#include <iostream>
using namespace std;
int main(){
	
	int buger=2000;
	int beverage=2000;
	int n=3;
	while(n--){
		int temp;
		cin >> temp;
		if(buger>temp)
			buger=temp;
	}
	n=2;
	while(n--){
		int temp;
		cin >> temp;
		if(beverage>temp)
			beverage=temp;
	}
	cout << buger+beverage-50;
}