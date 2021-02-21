import java.util.*;
class Solution {
    public int solution(int[] d, int budget) {
        int answer = 0;
        Arrays.sort(d);
        while(budget>0&&answer<d.length){
            if(d[answer]<=budget){
                budget-=d[answer];
                answer++;
            }
            else
                break;
        }
        return answer;
    }
}