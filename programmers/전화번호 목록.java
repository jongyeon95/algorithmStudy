class Solution {
    public boolean solution(String[] phone_book) {
        boolean answer = true;
        for (int i = 0; i < phone_book.length; i++) {
            for (int j = 0; j < phone_book.length; j++) {
                if (i == j)
                    continue;
                if (phone_book[j].startsWith(phone_book[i])) {
                    answer = false;
                    return answer;
                }
            }
        }
        return answer;
    }
}