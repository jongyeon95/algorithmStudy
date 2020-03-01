#include <iostream>
using namespace std;
int cage[100000]={3,7,17};
int main(){
	int n;
	cin >> n;
	if(cage[n-1]==0){
		for (int i = 3; i <n; i++)
		{
			cage[i]=(2*cage[i-1]+cage[i-2])%9901;
		}
	}
	cout << cage[n-1];

}