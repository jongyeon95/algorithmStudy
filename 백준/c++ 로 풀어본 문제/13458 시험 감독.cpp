#include <iostream>
using namespace std;
int main(){
	int n;
	int testSite[1000000];
	int SuperMan;
	int SubMan;
	long long result=0;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> testSite[i];
	}
	cin >> SuperMan >> SubMan;
	result+=n;
	for (int i = 0; i < n; ++i)
	{
		int temp;
		int tempRsult;
		temp=testSite[i]-SuperMan;
		if(temp<=0){
			continue;
		}
		else if(temp%SubMan==0){
			tempRsult=temp/SubMan;
		}
		else{
			tempRsult=temp/SubMan+1;
		}
		result+=tempRsult;
	}
	cout<<result;






}