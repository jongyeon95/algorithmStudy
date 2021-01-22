import java.util.*;

class Solution {
    public int[] solution(int[] array, int[][] commands) {
        int[] answer = new int[commands.length];
        for (int i = 0; i < commands.length; i++) {
            int[] temp = new int[commands[i][1] - commands[i][0] + 1];
            int flag = 0;
            for (int f = commands[i][0] - 1; f < commands[i][1]; f++) {
                temp[flag] = array[f];
                flag++;
            }
            Arrays.sort(temp);
            answer[i] = temp[commands[i][2] - 1];
        }
        return answer;
    }
}