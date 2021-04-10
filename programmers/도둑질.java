class Solution {
    public int solution(int[] money) {
        int answer = 0;
        int[][] dp=new int[2][money.length];
        dp[0][0]=money[0];
        dp[1][0]=0;
        dp[0][1]=Math.max(dp[0][0],money[1]);
        dp[1][1]=money[1];
        
        for(int i=2; i<money.length; i++){
            if(i<money.length-1)
                dp[0][i]=Math.max(dp[0][i-1],money[i]+dp[0][i-2]);
            dp[1][i]=Math.max(dp[1][i-1],money[i]+dp[1][i-2]);
            if(answer<dp[0][i]||answer<dp[1][i]){
                answer=Math.max(dp[0][i],dp[1][i]);
            }
        }
        return answer;
    }
}
