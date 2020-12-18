#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main()
{
	while (1)
	{
		int len;
		long long ans = 0;
		string str;
		cin >> str;
		if (str == "#")
			break;
		len = str.length();

		for (int i = 1; i <= len; i++)
		{
			int tmp;
			switch (str[i - 1])
			{
			case '-':
				tmp = 0;
				break;
			case '\\':
				tmp = 1;
				break;
			case '(':
				tmp = 2;
				break;
			case '@':
				tmp = 3;
				break;
			case '?':
				tmp = 4;
				break;
			case '>':
				tmp = 5;
				break;
			case '&':
				tmp = 6;
				break;
			case '%':
				tmp = 7;
				break;
			case '/':
				tmp = -1;
				break;
			default:
				break;
			}
			ans += tmp * pow(8, len - i);
		}
		cout << ans << '\n';
	}
}


