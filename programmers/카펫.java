class Solution {
  
    
    public int[] solution(int brown, int yellow) {
       
        int x=0;
        int y=0;
        for(int i=1; i<brown; i++){
            for(int j=1; j<=i; j++){
                if(2*i+2*j-4==brown&&i*j==brown+yellow){
                    x=i;
                    y=j;
                    break;
                }
            }
        }
        int[] answer = {x,y};
        return answer;
    }
}