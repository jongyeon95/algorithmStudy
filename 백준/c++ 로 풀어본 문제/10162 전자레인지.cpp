#include <iostream>
using namespace std;
int main(){
	int num;
	int arr[]={60*5,60,10};
	int result[]={0,0,0};
	cin >> num;
	for(int i=0; i<3; i++){
		result[i]=num/arr[i];
		num%=arr[i];
	}
	if(num==0){
		cout<<result[0]<<" "<<result[1]<<" "<<result[2];
	}
	else{
		cout<<-1;
	}
}