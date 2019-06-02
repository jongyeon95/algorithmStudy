#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int n;
	cin >> n;
	int line[n];
	int result=0;
	for (int i = 0; i < n; i++)
	{
		cin >> line[i];
	}
	sort(line,line+n);
	for (int i = 0; i < n; ++i)
	{
		for (int j = n-1-i; j>-1 ; j--)
		{
			result+=line[j];
		}
	}
	cout << result;

}