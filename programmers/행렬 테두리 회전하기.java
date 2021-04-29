class Solution {
    public static int[][] map;
    public int[] solution(int rows, int columns, int[][] queries) {
        int[] answer = new int[queries.length];
        map=new int[rows][columns];
        int cnt=1;
        for(int i=0; i<rows; i++){
            for(int j=0; j<columns; j++){
                map[i][j]=cnt;
                cnt++;
            }
        }
        for(int i=0;i<queries.length; i++){
            int y1=queries[i][0]-1;
            int x1=queries[i][1]-1;
            int y2=queries[i][2]-1;
            int x2=queries[i][3]-1;
            answer[i]=rotate(x1,y1,x2,y2);
        }
        return answer;
    }
    
    public static int rotate(int x1, int y1, int x2, int y2){
        int temp1;
        int temp2;
        temp1=map[y1+1][x1];
        int minNum=temp1;
        
        for(int i=x1; i<x2; i++){
            temp2=map[y1][i];
            map[y1][i]=temp1;
            temp1=temp2;
            if(minNum>temp2) minNum=temp2;           
        }
        
        for(int i=y1; i<y2; i++){
            temp2=map[i][x2];
            map[i][x2]=temp1;
            temp1=temp2;
             if(minNum>temp2) minNum=temp2;          
        }
        
        for(int i=x2; i>x1; i--){
            temp2=map[y2][i];
            map[y2][i]=temp1;
            temp1=temp2;
            if(minNum>temp2) minNum=temp2;     
          
        }
        
        for(int i=y2; i>y1; i--){
            temp2=map[i][x1];
            map[i][x1]=temp1;
            temp1=temp2;
            if(minNum>temp2) minNum=temp2;
          
        }                
        return minNum;
    }
}