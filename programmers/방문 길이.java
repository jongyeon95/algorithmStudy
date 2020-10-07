class Solution {
    public int solution(String dirs) {
        boolean visited[][][] = new boolean[11][11][2];
        int answer = 0;
        int cnt = 0;
        int y=5;
        int x=5;
        while(cnt<dirs.length()){
            char c=dirs.charAt(cnt);
            int dy=0;
            int dx=0;
            int dir=0;
            switch(c){
                case 'U' : 
                    dy=-1;
                    dir=0;
                    break;
                case 'D' :
                    dy=1;
                    dir=0;
                    break;
                case 'L' :
                    dir=1;
                    dx=-1;
                    break;
                case 'R' :
                    dir=1;
                    dx=1;
                    break;
            }
            int ty=dy+y;
            int tx=dx+x;
            if(ty<0||tx<0||tx>10||ty>10){
                cnt++;
                continue;
            }
            if(c=='R'){
                 if(!visited[y][tx][dir]){
                     visited[y][tx][dir]=true;
                     answer++;
                 }
            }
            else if(c=='D'){
                if(!visited[ty][x][dir]){
                     visited[ty][x][dir]=true;
                     answer++;
                 }
            }
            else{
                if(c=='L'&&x==0)
                    continue;
                if(c=='U'&&y==0)
                    continue;
                if(!visited[y][x][dir]){
                     visited[y][x][dir]=true;
                     answer++;
                 }
            }         
            y=ty;
            x=tx;
            cnt++;
        }
        
        
        return answer;
    }
}