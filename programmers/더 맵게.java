import java.util.*;

class Solution {
    public int solution(int[] scoville, int K) {
        int answer = 0;
        PriorityQueue<Integer> q = new PriorityQueue<>();
        for (int i = 0; i < scoville.length; i++) {
            q.offer(scoville[i]);
        }
        while (true) {
            if (q.isEmpty()) {
                return -1;
            }
            int temp = q.poll();
            if (temp < K) {
                if (q.isEmpty()) {
                    return -1;
                }
                temp += q.poll() * 2;
                q.offer(temp);
                answer++;
            } else {
                break;
            }
        }
        return answer;
    }
}