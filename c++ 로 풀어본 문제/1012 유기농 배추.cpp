#include <cstdio>

#include <string.h>

using namespace std;

 

int dx[4] = { 0,0,-1,1 };

int dy[4] = { 1,-1,0,0 };

int arr[52][52];

int T, n, m, k, ans;

 

void dfs(int x, int y) {

    arr[x][y] = 0;

    for (int i = 0; i < 4; ++i) {

        if (arr[x + dx[i]][y + dy[i]])

            dfs(x + dx[i], y + dy[i]);

    }

}

 

int main() {

    scanf("%d", &T);

    

    while (T--) {

        memset(arr, 0, sizeof(arr)), ans = 0;        //초기화

        scanf("%d %d %d", &m, &n, &k);

 

        for (int i = 0; i < k; ++i) {

            int x, y;

            scanf("%d %d", &x, &y);

 

            arr[++x][++y] = 1;

        }

 

        for (int i = 1; i <= m; ++i) {        //m이 가로, x, i

            for (int j = 1; j <= n; ++j) {    //n이 세로, y, j

                if (arr[i][j]) ans++, dfs(i, j);

            }

        }

 

        printf("%d\n", ans);

    }

 

    return 0;

}