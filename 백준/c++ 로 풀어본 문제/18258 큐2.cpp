#include <iostream>
#include <string>
using namespace std;
int q[2000000];
int flag=0;
int front=0;
int back=0;
int n;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		string s;
		cin >>  s;
		if(s[0]=='p'){
			if(s.size()==3){
				if(front==back){
					cout << "-1\n";
					continue;
				}
				cout << q[front] << "\n";
				q[front]=-1;
				front++;
			}
			else{
				cin >> q[back];
				back++;
			}
		}
		else if(s[0]=='f'){
			if(front==back){
				cout << "-1\n";
			}
			else{
				cout << q[front] << "\n";
			}

		}
		else if(s[0]=='b'){
			if(front==back){
				cout << "-1\n";
			}
			else{
				cout << q[back-1] << "\n";
			}
			
		}
		else if(s[0]=='s'){
			cout << back-front << "\n";
			
		}
		else if(s[0]=='e'){
			if(front==back){
				cout << "1\n";
			}
			else{
				cout <<"0\n";
			}
			
		}
	}
	


}