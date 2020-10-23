
#include <iostream>
#include <vector>
using namespace std;

int N, parrent[100001] = { 0, };
vector<int> connect[100001];

void Tree(int curr)
{
	for (int next : connect[curr])
	{
		if (parrent[next] == 0)
		{
			parrent[next] = curr;
			Tree(next);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	{
		cin >> N;
		int a, b;
		for (int i = 0; i < N - 1; i++)
		{
			cin >> a >> b;
			connect[a].push_back(b);
			connect[b].push_back(a);
		}
	}

	Tree(1);

	for (int i = 2; i <= N; i++)
		cout << parrent[i] << '\n';

	return 0;
}