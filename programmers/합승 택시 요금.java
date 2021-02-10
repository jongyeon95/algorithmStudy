class Solution {
    
    public static int area[][];
    
    public int solution(int n, int s, int a, int b, int[][] fares) {
        int answer = 0;
        area= new int[n+1][n+1];
        
        for(int i=0; i<=n; i++){
            for(int j=0; j<=n; j++){
                if(i==j)
                    continue;
                area[i][j]=Integer.MAX_VALUE;
            }
        }
        
        for(int i=0; i<fares.length; i++){
            area[fares[i][0]][fares[i][1]]=fares[i][2];
            area[fares[i][1]][fares[i][0]]=fares[i][2];
        }
        
        for(int k=1; k<=n; k++){
            for(int i=1; i<=n; i++){
                for(int j=1; j<=n; j++){
                    if(area[i][k]+area[k][j]>=0&&area[i][j]>area[i][k]+area[k][j]){
                        area[i][j]=area[i][k]+area[k][j];
                    }
                }
            }
        }
        answer=area[s][a]+area[s][b];
        for(int i=1; i<=n; i++){
            if(area[s][i]+area[i][a]+area[i][b]<answer){
                answer=area[s][i]+area[i][a]+area[i][b];
            }
        }
        
        
        return answer;
    }
    
    
}