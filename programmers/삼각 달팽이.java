class Solution {
    public int[] solution(int n) {
        int dy[]={1,0,-1};
        int dx[]={0,1,-1};
        int arr[][]=new int[n][n];
        int y=0;
        int x=0;
        int cnt=1;
        int flag=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                arr[i][j]=0;
            }
        }
        while(true){
            arr[y][x]=cnt;
            if(cnt==n*(n+1)/2)
                break;
            int ty=y+dy[flag];
            int tx=x+dx[flag];
            if(ty<0||tx<0||ty>=n||tx>=n||arr[ty][tx]!=0){
                flag++;
                if(flag==3)
                    flag=0;
            }
            else{
                cnt++;
                y=ty;
                x=tx;
            }
            
        }
        
        int[] answer = new int[n*(n+1)/2];
        int arrcnt=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<=i; j++){
                answer[arrcnt]=arr[i][j];
                arrcnt++;
            }
        }
        return answer;
    }
}