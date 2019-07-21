#include <iostream>


using namespace std;

int main(){
int N;
cin >> N;
int arr[N];
for (int i = 0; i < N; i++)
{
	cin >> arr[i];
}

for (int i = 0; i < N; ++i)
{
	for(int j=0; j<N-i-1;j++){
		if(arr[j]>arr[j+1]){
			int temp=arr[j+1];
			arr[j+1]=arr[j];
			arr[j]=temp;
		}
	}
}

for (int i = 0; i < N; ++i)
{
	cout << arr[i] << "\n";
}



}