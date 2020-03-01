#include <iostream>
#include <cstring>
using namespace std;
int main(){
	int mod[100];
	int result=0;
	int n, p;
	cin >> n >> p;
	memset(mod,0,sizeof(mod));
	int temp=n;
	while(1){
		temp=(temp*n)%p;
		if(mod[temp]==3){
			break;
		}
		else{
			mod[temp]++;
		}
	}

	for (int i = 0; i <=97; ++i)
	{
		if(mod[i]==3)
			result++;
	}

	cout << result;

}