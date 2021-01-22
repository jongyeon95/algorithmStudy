class Solution {
    public int solution(int n) {
        int answer = 0;
        int num = 0;
        int minusNum = 1;
        int addNum = 1;
        while (!(minusNum >= n && addNum >= n)) {
            if (num == n) {
                answer++;
                if (addNum > n)
                    continue;
                num += addNum;
                addNum++;
            } else if (num < n) {
                if (addNum > n)
                    continue;
                num += addNum;
                addNum++;
            } else {
                if (minusNum > n)
                    continue;
                num -= minusNum;
                minusNum++;
            }
        }
        return answer + 1;
    }
}