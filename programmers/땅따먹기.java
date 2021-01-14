class Solution {
    int solution(int[][] land) {
        int answer = 0;
        int[][] result= new int[land.length][4];
        for(int i=0; i<land.length; i++){
            for(int j=0; j<4; j++){
                if(i==0){
                    result[i][j]=land[i][j];   
                }
                else{
                    int maxNum=0;
                    for(int k=0; k<4; k++){
                        if(k==j){
                            continue;
                        }
                        if(result[i-1][k]>maxNum){
                            maxNum=result[i-1][k];
                        }
                    }
                    result[i][j]=maxNum+land[i][j];
                }
            }
        }
        for(int i=0; i<4; i++){
            if(answer<result[land.length-1][i]){
                answer=result[land.length-1][i];
            }
        }
      

        return answer;
    }
}