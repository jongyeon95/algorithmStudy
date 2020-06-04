#include <iostream>
using namespace std;
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	int testcase;
	cin >> testcase;
	for (int t= 1; t <= testcase; t++)
	{
		long year;
		long month;
		cin >> year >> month;
		long temp=year-2016;
		if(temp!=0){
			month+=temp*12;
			if(month%13==0){
				year=2016+month/13-1;
				month=13;
			}
			else{
				year=2016+month/13;
				month%=13;
			}
		}
		cout << "#" << t << " "<<year<<" "<< month <<"\n";
	}

}