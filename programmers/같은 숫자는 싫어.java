import java.util.*;

public class Solution {
    public int[] solution(int[] arr) {
        ArrayList<Integer> a = new ArrayList<Integer>();
        for (int i = 0; i < arr.length - 1; i++) {
            if (arr[i] != arr[i + 1]) {
                a.add(arr[i]);
            }
        }

        a.add(arr[arr.length - 1]);

        int[] answer = new int[a.size()];

        for (int i = 0; i < a.size(); i++) {
            answer[i] = a.get(i);
        }


        return answer;
    }
}