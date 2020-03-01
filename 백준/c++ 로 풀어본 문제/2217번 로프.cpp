#include <iostream>
#include <algorithm>


using namespace std;


int main(){

int result=0;
int n;
cin>>n;
int rope[n];
for (int i = 0; i < n; i++)
{
	cin>>rope[i];
}
sort(rope,rope+n);
for (int i = 0; i < n; i++)
{
	if(result<rope[i]*(n-i)){
		result=rope[i]*(n-i);
	}

}

cout<<result;

}
