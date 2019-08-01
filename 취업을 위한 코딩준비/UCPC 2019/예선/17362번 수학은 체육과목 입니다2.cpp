#include <iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	int check=n%8;
	if(check==1){cout << 1;}
		else if(check==5){cout << 5;}
			else if(check==2||check==0){cout << 2;}
				else if(check==3||check==7){cout << 3;}
					else if(check==4||check==6){cout << 4;}
}