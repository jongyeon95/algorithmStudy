#include <iostream>


using namespace std;


int main(){

int money;
int result=0;
int coin[6]={500,100,50,10,5,1};
int temp=0;
int i=0;
cin >> money;
money=1000-money;
while(money!=0){
	result+=money/coin[i];
	money=money%coin[i];
	i++;
}
cout << result;

}
