#include <iostream>
using namespace std;
int main(){
	while(1){
		string s;
		int age;
		int weight;
		cin >> s >> age >> weight;
		if(s=="#"){
			return 0;
		}
		cout<<s<<" ";
		if(age>17||weight>=80){
			cout<<"Senior\n";
		}
		else{
			cout<<"Junior\n";
		}

	}
}