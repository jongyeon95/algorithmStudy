class Solution {
    public int[] solution(int[] lottos, int[] win_nums) {
       
        int[] score={6,6,5,4,3,2,1};
        int zeroCnt=0;
        boolean[] num= new boolean[46];
        for(int temp : lottos){
            if(temp==0)
                zeroCnt++;
            else
                num[temp]=true;
        }
        int correct=0;
        for(int temp : win_nums){
            if(num[temp])
                correct++;
        }
        int maxScore=zeroCnt+correct;
        int minScore=correct;
        int[] answer = {score[maxScore],score[minScore]};
        return answer;
    }
}