#include <iostream>
using namespace std;
int main(){
	int a,b,c;
	int result=1;
	cin >> a >> b >> c;
	if(b>=c){
		cout<<-1;
		return 0;
	}
	cout<<a/(c-b)+1;
}