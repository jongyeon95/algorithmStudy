#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;




void D(deque<int> &d , bool rv){
	if(rv)
		d.pop_back();
	else
		d.pop_front();
}

int main(){
	int testcase;
	cin >> testcase;
	while(testcase--){
		deque<int> dq;
		string command;
		string arr;
		int arrSize;
		cin >> command;
		cin >> arrSize;
		cin >> arr;
		int temp=0;
		bool errorCheck=false;
		for (int i = 0; i < arr.size(); i++)
		{
			if(arrSize!=0){
				if(arr[i]=='[')
					continue;
				if(arr[i]==','||arr[i]==']'){
					dq.push_back(temp);
					temp=0;
				}
				else{
					temp*=10;
					temp+=arr[i]-'0';
				}
			}
		}
		bool RV=false;

		for (int i = 0; i < command.size(); ++i)
		{
			if(command[i]=='R'){
				if(dq.size()!=0&&dq.size()!=1){
					RV= !RV;	
				}
			}
			else{
				if(dq.size()==0){
					errorCheck=true;
					break;
				}
				else{
					D(dq , RV);
				}
			}
		}

		if(errorCheck)
			cout << "error" <<endl;
		else if(dq.size()==0)
			cout <<"[]"<<endl;
		else{
			cout << "[";
			if(RV){
				for (int i = dq.size()-1; i >0; i--)
				{
					cout << dq[i] << ",";
				}
	
				cout << dq[0] << "]" <<endl;
			}
			else{
				for (int i = 0; i < dq.size()-1; ++i)
				{
				cout << dq[i] << ",";
				}

				cout << dq[dq.size()-1] << "]" <<endl;
				}

			}
		}
	}
