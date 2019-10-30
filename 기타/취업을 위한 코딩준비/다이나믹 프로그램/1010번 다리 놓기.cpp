#include <iostream>

int dp[31];

int main() {

	int T;

	scanf("%d", &T);

	while (T--) {

		int N, M;

		scanf("%d %d", &N, &M);

		for (int i = 0; i <= 30; ++i) {

			dp[i] = 0;

		}

		dp[N] = 1;

		for (int i = N + 1; i <= M; ++i) {

			dp[i] = dp[i - 1] * i / (i-N);

		}

		printf("%d\n", dp[M]);

	}

}



