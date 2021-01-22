import java.util.*;

class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        int flag = 0;
        ArrayList<Integer> ans = new ArrayList<Integer>();
        while (flag != speeds.length) {
            for (int i = flag; i < progresses.length; i++) {
                progresses[i] += speeds[i];
            }
            if (progresses[flag] >= 100) {
                int cnt = 0;
                for (int i = flag; i < progresses.length; i++) {
                    if (progresses[i] >= 100) {
                        cnt++;
                        flag = i + 1;
                    } else
                        break;
                }
                ans.add(cnt);
            }
        }
        int[] answer = new int[ans.size()];
        for (int i = 0; i < ans.size(); i++)
            answer[i] = (int) ans.get(i);


        return answer;
    }
}