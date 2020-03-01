#include <iostream>;
#include <string>;
#include <stack>;
using namespace std;
int main(void)
{
	string tmp;
	while (1)
	{
		getline(cin, tmp);
		if (tmp == ".")
			break;
		int len = tmp.length();
		bool check = true;
		stack<char> st;
		for (int i = 0; i < len; i++)
		{
			if (tmp[i] == '(')
			{
				st.push(tmp[i]);
			}
			else if (tmp[i] == '[')
			{
				st.push(tmp[i]);
			}
			else if (tmp[i] == ')')
			{
				if (st.empty())
				{
					check = false;
					break;
				}
				if (st.top() == '(')
					st.pop();
				else
				{
					check = false;
					break;
				}
			}
			else if (tmp[i] == ']')
			{
				if (st.empty())
				{
					check = false;
					break;
				}
				if (st.top() == '[')
					st.pop();
				else
				{
					check = false;
					break;
				}
			}
		}
		if (check && st.empty())
			cout << "yes\n";
		else
			cout << "no\n";
	}
}