#include <iostream>
#include <string>

using namespace std;

int main(){
	string a,b;
	int count=0;
	int min=9999;
	cin >> a >> b;
	for(int i=0;i<=(b.length()-a.length());i++){
		count=0;
		for(int j=0;j<a.length();j++){
			if(b[i+j]!=a[j]){count++;}

		}
		if(min>count){
			min=count;
		}
		

	}
	cout << min;
}