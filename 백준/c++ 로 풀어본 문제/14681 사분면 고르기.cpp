#include <iostream>
using namespace std;
int main(){
	int x,y;
	int result;
	cin >> x >> y;
	if(x>0){
		if(y>0)
			result=1;
		else
			result=4;

	}
	else{
		if(y>0)
			result=2;
		else
			result=3;
	}
	cout << result;
}