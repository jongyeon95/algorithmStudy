import java.util.*;

class Solution {
    public int solution(int[] nums) {
        int answer = 0;
        HashSet<Integer> hs = new HashSet<>();
        answer = nums.length / 2;
        for (int num : nums) {
            hs.add(num);
        }
        if (hs.size() < answer)
            answer = hs.size();
        return answer;
    }
}