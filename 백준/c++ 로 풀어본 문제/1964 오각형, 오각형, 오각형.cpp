#include <iostream>
#include <algorithm>
using namespace std;
 
int main()
{
	int n;
	int num;
	int result;
 
	result = 5;
	num = 7;
	
	cin >> n;
 
	for (int i = 2; i <= n; ++i, num+=3) {
		result += num;
		result %= 45678;
	}
 
	cout << result << endl;
 
	return 0;
}

