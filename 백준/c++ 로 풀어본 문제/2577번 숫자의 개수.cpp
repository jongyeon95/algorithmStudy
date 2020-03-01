#include <iostream>
using namespace std;
int main(){
	int a,b,c;
	int sum=0;
	int result[10]={0};
	cin >>a>>b>>c;
	sum=a*b*c;
	while(sum>0){
		int a;
		a=sum%10;
		result[a]++;
		sum/=10;
	}
	for (int i = 0; i < 10; i++)
	{
			cout<<result[i]<<endl;
	}

}