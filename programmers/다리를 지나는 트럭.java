import java.util.*;

class Solution {
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        Queue<Integer> q = new LinkedList<Integer>();
        int answer = 0;
        int bWeight = 0;
        int flag = 0;
        for (int i = 0; i < bridge_length; i++) {
            q.offer(0);
        }
        while (flag < truck_weights.length) {
            bWeight -= q.element();
            q.remove();
            answer++;
            if (bWeight + truck_weights[flag] <= weight) {
                q.offer(truck_weights[flag]);
                bWeight += truck_weights[flag];
                flag++;
            } else {
                q.offer(0);
            }


        }
        answer += bridge_length;

        return answer;
    }
}