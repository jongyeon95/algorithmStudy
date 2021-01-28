class Solution {
    
    public static boolean visited[][];
    
    public int[] solution(int[][] arr) {
        int[] answer = {0,0};
        visited= new boolean[arr.length][arr[0].length];
        int size=arr.length;
        while(size>0){
            for(int i=0; i<arr.length; i+=size){
                for(int j=0; j<arr.length; j+=size){
                    int result=check(i,j,size,arr);
                    if(result==0)
                        answer[0]++;
                    else if(result==1)
                        answer[1]++;
                }
            }
            size/=2;
        }
        return answer;
    }
    
    public int check(int startY,int startX,int size,int[][] arr){
        int temp=arr[startY][startX];
        for(int i=startY; i<startY+size; i++){
            for(int j=startX; j<startX+size; j++){
               if(visited[i][j]||arr[i][j]!=temp){
                   return -1;
               }
            }
        }
        for(int i=startY; i<startY+size; i++){
            for(int j=startX; j<startX+size; j++){
               visited[i][j]=true;
            }
        }
        
        return temp;
    }
}