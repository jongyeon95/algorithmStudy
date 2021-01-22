class Solution {
    public int solution(String arrangement) {
        int answer = 0;
        int flag = 0;
        for (int i = 0; i < arrangement.length(); i++) {
            if (arrangement.charAt(i) == '(') {
                flag++;
            } else {
                flag--;
                if (arrangement.charAt(i - 1) == '(')
                    answer += flag;
                else
                    answer += 1;
            }
        }
        return answer;
    }
}