#include <iostream>
using namespace std;
int main(){
	cin.tie(0);
	cout.sync_with_stdio(false);
	int testcase;
	cin  >> testcase;
	for (int t = 1; t <= testcase; ++t)
	{
		int result=0;
		int n;
		cin >> n;
		int arr[n+1];
		int temp;
		for (int i = 1; i <= n; ++i)
		{
			cin>>temp;
			arr[i]=temp%3;
		}
		for (int i = 1; i <= n; ++i)
		{
			if(i%3!=arr[i]){
				bool check=false;
				for (int j = i+1; j <=n ; ++j)
				{
					if(i%3==arr[j]&&arr[i]==j%3){
						check=true;
						int temp= arr[j];
						arr[j]= arr[i];
						arr[i]=temp;
						result++;
						break;
					}
				}
				if(!check){
					for (int j = i+1; j <=n ; ++j)
					{
						if(i%3==arr[j]&&i%3!=j%3){
							int temp= arr[j];
							arr[j]= arr[i];
							arr[i]=temp;
							result++;
							break;
						}
						
					}
				}

			}
		}
		cout << "#" << t<<" "<<result<<"\n";
	}
}