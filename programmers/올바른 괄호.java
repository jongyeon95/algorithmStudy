import java.util.*;

class Solution {
    boolean solution(String s) {
        boolean answer = true;
        Queue<Character> q = new LinkedList<Character>();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                q.offer('(');
            } else {
                if (q.size() == 0)
                    return false;
                else
                    q.poll();
            }
        }
        if (q.size() > 0)
            return false;

        return answer;
    }
}