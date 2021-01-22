class Solution {

    public static boolean[] num = new boolean[1000001];


    public int solution(int n) {
        int answer = n - findPn(n);
        return answer;
    }

    public int findPn(int n) {
        int answer = 1;
        for (int i = 2; i <= n / 2; i++) {
            if (!num[i]) {
                for (int j = i * 2; j <= n; j += i) {
                    if (num[j])
                        continue;
                    num[j] = true;
                    answer++;
                }
            }
        }
        return answer;

    }
}