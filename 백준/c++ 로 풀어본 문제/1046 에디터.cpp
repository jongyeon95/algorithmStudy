#include <iostream>

#include <string>

#include <stack>

using namespace std;





int main()

{

	stack<char> list1, list2;



	string inputstr;

	int loop;

	char order;

	cin >> inputstr;

	cin >> loop;



	for (int i = 0; i < inputstr.length(); i++)

	{

		list1.push(inputstr[i]);

	}



	for (int i = 0; i < loop; i++)

	{

		cin >> order;

		if (order == 'L' && !list1.empty())

		{

			list2.push(list1.top());

			list1.pop();

		}

		else if (order == 'D' && !list2.empty())

		{

			list1.push(list2.top());

			list2.pop();

		}

		else if (order == 'B' && !list1.empty())

		{

			list1.pop();

		}

		else if(order == 'P')

		{

			cin >> order;

			list1.push(order);

		}

	}



	while (!list1.empty())

	{

		list2.push(list1.top());

		list1.pop();

	}



	while (!list2.empty())

	{

		cout << list2.top();

		list2.pop();

	}

	cout << endl;



	return 0;

}