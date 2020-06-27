class Solution {
    public int[] solution(int[] heights) {

        int[] answer = new int[heights.length];
        //오른쪽 부터 시작 
        for(int i=heights.length-1; i>=1; i--){
            for(int j=i-1; j>=0; j--){
                // 자신보다 높은 건물이 있으면 탈출
                if(heights[i]<heights[j]){
                    answer[i]=j+1;
                    break;
                }
            }
        }
        return answer;
    }
}