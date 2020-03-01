#include <iostream>


using namespace std;

int main(){
int N;
cin >> N;
int arr[N];
int sw=1;
int i;
for (int i = 0; i < N; i++)
{
	cin >> arr[i];
}

for (int j = 1; j < N; j++)
{
i=j-1;
int temp=arr[j];
sw=1;
	while(sw){
		if(temp<arr[i]){
		arr[i+1]=arr[i];
		i=i-1;
		if(i<0){sw=0;}
		}
		else
			sw=0;
	}
	arr[i+1]=temp;
}

for (int i = 0; i < N; i++)
{
	cout << arr[i] << "\n";
}



}