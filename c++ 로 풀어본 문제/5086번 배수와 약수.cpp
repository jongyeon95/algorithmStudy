#include <iostream>
using namespace std;
int main(){
	int a,b;
	int check;
	while(1){
		check=3;
		cin >> a >> b;
		if(a==0&&b==0)
			return 0;
		if(a<=b){
			if(b%a==0)
				check=1;
		}
		else if(a>=b)
			if(a%b==0)
				check=2;

	if(check==1)
		cout << "factor" << endl;
	else if(check==2)
		cout << "multiple" << endl;
	else
		cout << "neither" << endl;
	}
}