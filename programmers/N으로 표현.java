class Solution {
    
    public int answer;
    public int resultNum;
  
    void dfs(int N, int num, int cnt ,int acc){
        int nn=N;
        
        if(cnt>8){
            return;
        }
        
        if(num==acc){
            if(answer>cnt){
                answer=cnt;
            }
            return;
        }
        for(int i=1; i<9-cnt; i++ ){
            dfs(N,num,cnt+i,acc+nn);
            dfs(N,num,cnt+i,acc/nn);
            dfs(N,num,cnt+i,acc*nn);
            dfs(N,num,cnt+i,acc-nn);
            nn=nn*10+N;
        }
        
    }
    
    
    public int solution(int N, int number) {
        answer = 9;
        dfs(N,number,0,0);
        if(answer==9){
            return -1;
        }
        
        return answer;
    }
}