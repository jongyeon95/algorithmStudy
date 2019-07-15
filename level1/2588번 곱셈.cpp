#include <iostream>
#include <math.h>

using namespace std;

void intToArr(int Arr[], int num, int size)
{
	for (int i = size - 1; i >= 0; i--)
	{
		Arr[i] = num % 10;
		num /= 10;
	}
}


int main()
{
	int x, y; // 입력받을 숫자

	int num1[3] = {};
	int num2[3] = {};
	int mul[3] = {};
	int result = 0;

	cin >> x >> y;

	intToArr(num1, x, 3);
	intToArr(num2, y, 3);

	for (int i = 2; i >= 0; i--)
	{
		for (int j = 2; j >= 0; j--)
		{
			mul[i] += num1[j] * num2[i] * (int)pow(10, 2-j);
		}
		result += mul[i] * (int)pow(10, 2 - i);
	}

	for (int i = 2; i >=0; i--)
	{
		cout << mul[i] << "\n";
	}
	cout << result;
}

