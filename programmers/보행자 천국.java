class Solution {
    int MOD = 20170805;

    public int solution(int m, int n, int[][] cityMap) {
        int answer = 0;
        int arr1[][] = new int[m + 1][n + 1];
        int arr2[][] = new int[m + 1][n + 1];
        for (int i = 0; i < m + 1; i++) {
            for (int j = 0; j < n + 1; j++) {
                arr1[i][j] = 0;
                arr2[i][j] = 0;
            }
        }
        arr1[1][1] = 1;
        arr2[1][1] = 1;
        for (int i = 1; i < m + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                if (cityMap[i - 1][j - 1] == 0) {
                    arr1[i][j] += (arr1[i - 1][j] + arr2[i][j - 1]) % 20170805;
                    arr2[i][j] += (arr1[i - 1][j] + arr2[i][j - 1]) % 20170805;
                } else if (cityMap[i - 1][j - 1] == 1) {
                    arr1[i][j] = 0;
                    arr2[i][j] = 0;
                } else {
                    arr1[i][j] = arr1[i - 1][j];
                    arr2[i][j] = arr2[i][j - 1];

                }
            }
        }
        return arr1[m][n];
    }
}