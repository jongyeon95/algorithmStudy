#include <iostream>
using namespace std;
int main(){
	int N;
	long long Case[1000001]; //long long  안해주면 1000000009연산이 값이 이상하게 나온다.
	Case[0]=0;
	Case[1]=1;
	Case[2]=2;
	Case[3]=4;
	int temp=3;
	cin >> N;

	for(int i=0;i<N;i++){
		int num;
		cin >> num;
		if (num>temp)
		{
			for (int j = temp+1; j <=num; j++)
			{
				Case[j]=Case[j-1]+Case[j-2]+Case[j-3];
				Case[j]=Case[j]%1000000009;
			}
			temp=num;

			cout << Case[num] << endl;
		}
		else
			cout << Case[num] << endl;

	}

}