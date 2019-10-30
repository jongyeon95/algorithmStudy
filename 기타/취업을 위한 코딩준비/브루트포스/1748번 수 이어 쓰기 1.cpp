#include <iostream>
using namespace std;
int main(){
	int n;
	int temp=9;
	int temp2=0;
	int how10=1;
	int count=1;
	int result=0;
	bool check=true;
	cin >> n;
	temp2=n;
	
	while(true){
		if(temp2<10)
			break;
		temp2/=10;
		how10*=10;
		count++;
	}

	if(count==1)
	{
		for (int i = 0; i < n; i++)
		{
			result+=1;
		}

	}
	else{

		for (int i = 1; i < count; i++)
		{			
			result+=temp*i;
			temp=temp*10;
		}

		for (int i=temp/9; i <= n; i++)
		{
			result+=count;
		}

	}

	cout << result;






	

}