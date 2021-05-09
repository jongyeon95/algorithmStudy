class Solution
{
    public int solution(int [][]board)
    {   int row=board.length;
        int col=board[0].length;
        int answer=0;
        int[][] map = new int[row+1][col+1];
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                map[i+1][j+1]=board[i][j];
                if(map[i+1][j+1]!=0){
                    map[i+1][j+1]=Math.min(Math.min(map[i][j],map[i][j+1]),map[i+1][j])+1;
                    answer=Math.max(answer,map[i+1][j+1]);
                }
            }
        }
        
        return answer*answer;
    }
    
}
