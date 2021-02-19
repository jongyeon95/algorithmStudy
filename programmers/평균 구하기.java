class Solution {
    public double solution(int[] arr) {
        double answer = 0;
        for(int temp : arr)
            answer+=temp;
        answer/=arr.length;
        return answer;
    }
}