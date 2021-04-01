import java.util.*;
class Solution {
    public static int[] dy={1,-1,0,0};
    public static int[] dx={0,0,1,-1};
    public static boolean[][] visited;
    public static int ySize;
    public static int xSize;
    
    public int solution(int[][] maps) {
        ySize=maps.length;
        xSize=maps[0].length;
        visited=new boolean[ySize][xSize];
        int answer = 987654321;
        Queue<Robot> q=new LinkedList<Robot>();
        visited[0][0]=true;
        q.offer(new Robot(0,0,1));
        while(!q.isEmpty()){
            Robot temp=q.poll();
            for(int i=0; i<4; i++){
                int ty=temp.y+dy[i];
                int tx=temp.x+dx[i];
                if(ty<0||tx<0||ty>=ySize||tx>=xSize||visited[ty][tx]||maps[ty][tx]==0){
                    continue;
                }
                if(ty==ySize-1&&tx==xSize-1){
                    if(temp.cnt+1<answer)
                        answer=temp.cnt+1;
                    continue;
                }
                visited[ty][tx]=true;
                q.offer(new Robot(ty,tx,temp.cnt+1));
            }
        }
        if(answer==987654321)
            answer=-1;
        return answer;
    }
    
}

class Robot{
    int y;
    int x;
    int cnt;
    
    public Robot(int y, int x, int cnt){
        this.y=y;
        this.x=x;
        this.cnt=cnt;
    }
} 