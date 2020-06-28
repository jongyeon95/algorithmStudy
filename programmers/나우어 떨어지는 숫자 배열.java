import java.util.Arrays;
import java.util.ArrayList;

class Solution {
    public int[] solution(int[] arr, int divisor) {
        Arrays.sort(arr);
        ArrayList<Integer> a = new ArrayList<Integer>();
        for(int i=0; i<arr.length; i++){
            if(arr[i]>=divisor && arr[i]%divisor==0){
                a.add(arr[i]);
            }
        }
        if(a.size() == 0){
            int[] answer={-1};
            return answer;
        }
           
        int[] answer = a.stream().mapToInt(i -> i).toArray();
        
            
        return answer;
    }
}