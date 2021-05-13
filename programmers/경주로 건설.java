import java.util.*;
class Solution {
    public static int[] dy={0,0,-1,1};
    public static int[] dx={1,-1,0,0};
    public int solution(int[][] board) {
        int answer = bfs(board);
        
        
        return answer;
    }
    
    public static int bfs(int[][] map){
        int answer=0;
        Queue<Road> q = new LinkedList<>();
        map[0][0]=100;
        for(int i=0; i<4; i++){
            if(dy[i]<0||dx[i]<0) continue;
            if(map[dy[i]][dx[i]]!=1){
                map[dy[i]][dx[i]]=100;
                q.offer(new Road(dy[i],dx[i],100,i));
            }
        }
        while(!q.isEmpty()){
            Road temp = q.poll();
            if(temp.y==map.length&&temp.x==map[0].length)
                continue;
            for(int i=0; i<4; i++){
                int ty=temp.y+dy[i];
                int tx=temp.x+dx[i];
                if(ty<0||tx<0||ty>=map.length||tx>=map[0].length)
                    continue;
                if(map[ty][tx]==1)
                    continue;
                if(i==temp.dir){
                    if(map[ty][tx]>=temp.cost+100||map[ty][tx]==0){
                        map[ty][tx]=temp.cost+100;
                        q.offer(new Road(ty,tx,temp.cost+100,i));
                    }
                }
                else{
                    if(map[ty][tx]>=temp.cost+600||map[ty][tx]==0){
                        map[ty][tx]=temp.cost+600;
                        q.offer(new Road(ty,tx,temp.cost+600,i));
                    }
                }
            }
        }
        
        
        return map[map.length-1][map[0].length-1];
    }
}
class Road{
    int y;
    int x;
    int cost;
    int dir;
    public Road(int y, int x, int cost, int dir){
        this.y=y;
        this.x=x;
        this.cost=cost;
        this.dir=dir;
    }
}