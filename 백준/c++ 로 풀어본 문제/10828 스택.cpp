#include <iostream>
#include <string>
using namespace std;
int main(){
	int n;
	cin >> n;
	int StackArr[n];
	int StackSize=0;

	while(n--){
		string s;
		cin >> s;
		if(s[0]=='p'){
			if(s.size()>3){
				int temp;
				cin >> temp;
				StackArr[StackSize]=temp;
				StackSize++;
			}
			else{
				if(StackSize==0){
					cout << -1 <<endl;
				}
				else{
				cout << StackArr[StackSize-1] <<endl;
				StackArr[StackSize-1]=-1;
				StackSize--;
				}
			}

		}
		else if(s[0]=='t'){
			if(StackSize==0)
				cout << -1 <<endl;
			else
				cout << StackArr[StackSize-1] <<endl;
		}
		else if(s[0]=='e'){
			if(StackSize==0){
				cout << 1 <<endl;
			}
			else{
				cout << 0 <<endl;
			}

		}
		else if(s[0]=='s'){
			cout << StackSize << endl;

		}


	}
}