#include <iostream>
using namespace std;
int sol(int count, int sum, int goal ){
	if(sum>goal){return 0;}
	if(sum==goal){return 1;}
	int now= 0;
	for (int i = 1; i <= 3; i++)
	{
		now+=sol(count+1,sum+i,goal);
	}
	return now;


}


int main(){
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		cout << sol(0,0,num)<< endl;

	}

}