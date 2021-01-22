import java.util.*;

class Solution {
    public int[] solution(int[] numbers) {

        ArrayList<Integer> al = new ArrayList<>();
        TreeSet<Integer> t = new TreeSet<>();
        for (int i = 0; i < numbers.length; i++) {
            for (int j = i + 1; j < numbers.length; j++) {
                t.add(numbers[i] + numbers[j]);
            }
        }
        for (Integer a : t) {
            al.add(a);
        }
        int[] answer = new int[al.size()];
        for (int i = 0; i < answer.length; i++) {
            answer[i] = al.get(i);
        }

        return answer;
    }
}