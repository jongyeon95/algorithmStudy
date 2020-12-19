#include <iostream>
#include <string>
using namespace std;
int main(){
	int cnt=0;
	while(1){
		string s;
		getline(cin,s);
		if(s.empty()){
			cout<< cnt;
			return 0;
		}
		cnt++;
	}
}