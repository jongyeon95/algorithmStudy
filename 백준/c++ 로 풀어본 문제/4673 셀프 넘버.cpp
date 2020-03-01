#include <iostream>
#include <cstring>
using namespace std;

bool SelfNum[10001];

int SumNum(int a){
	int temp=a;
	while(1){
		if(a==0)
			break;
		temp+=a%10;
		a/=10;
	}
	return temp;
}

int main(){

	memset(SelfNum,true,sizeof(SelfNum));
	for(int i=1; i<10001;i++){
		int temp;
		temp=SumNum(i);
		SelfNum[temp]=false;
		
	}

	for (int i = 1; i < 10001; i++)
	{
		if(SelfNum[i])
			cout<< i <<"\n";
	}

}