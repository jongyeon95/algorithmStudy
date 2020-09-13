#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		int result = 1;

		for (int i = 1; i <= b; i++)
		{
			result *= a;
			if (result > 10)
			{
				result %= 10;
			}
		}
		if (result == 0)
			cout << "10" << endl;
		else
			cout << result << endl;
	}

	return 0;
}