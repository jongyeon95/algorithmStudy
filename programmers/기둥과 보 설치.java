import java.util.*;
class Frame implements Comparable<Frame> {
    int x;
    int y;
    int type; // 0 기둥 // 1 보
    
    public Frame(int x, int y, int type){
        this.y=y;
        this.x=x;
        this.type=type;
    }
    
    @Override
    public int compareTo(Frame o){
        if(this.x==o.x){
            if(this.y==o.y){
                return this.type-o.type;
            }
            return this.y-o.y;
        }
        return this.x- o.x;
    }
    
    public int[] FrameToArray(){
        int [] list= new int[3];
        list[0]=this.x;
        list[1]=this.y;
        list[2]=this.type;
        return list;
    }
    
    
}

class Solution {
    
    public static boolean [][][] map;
    public static int mapSize;
    public static ArrayList<Frame> list;
    
    public int[][] solution(int n, int[][] build_frame) {
        int[][] answer;
        map=new boolean[n+1][n+1][2];
        mapSize=n+1;
        list=new ArrayList<>();
        for(int i=0; i<build_frame.length; i++){
            isCan(build_frame[i][0],build_frame[i][1],build_frame[i][2],build_frame[i][3]);
        }
        
        for(int i=0; i<=n; i++){
            for(int j=0; j<=n; j++){
                for(int k=0; k<2; k++){
                    if(map[i][j][k]){
                        list.add(new Frame(j,i,k));
                    }
                }
            }
        }
        
        Collections.sort(list);
        answer=new int[list.size()][3];
        for(int i=0; i<list.size(); i++){
            answer[i]=list.get(i).FrameToArray();
        }
        return answer;
    }
    
    public static void isCan(int x, int y, int type, int command){
        if(command==0){//삭제 
            if(map[y][x][type]){
                if(type==0){//기둥
                    if(y>=mapSize-1){
                        map[y][x][0]=false;
                        return;
                    }
                    if(map[y+1][x][1]){
                        if(!(x>0&&x<mapSize-1&&map[y+1][x-1][1]&&map[y+1][x+1][1])){
                            if(!map[y][x+1][0])
                                return;
                        }
                    }
                    
                    if(x>0&&map[y+1][x-1][1]){
                        if(!map[y][x-1][0]){
                            if(!(x>1&&map[y+1][x-2][1]&&map[y+1][x][1]))
                                return;
                        }
                    }
                    
                    if(map[y+1][x][0]){
                        if(!(map[y+1][x][1]||(x>0&&map[y+1][x-1][1]))){
                            return;
                        }
                    }
                    map[y][x][0]=false;
                }
                else{//보
                    if(map[y][x][0]){
                        if(!map[y-1][x][0]&&!(x>0&&map[y][x-1][1])){
                            return;
                        }
                    }
                    
                    if(map[y][x+1][0]){
                        if(!(map[y-1][x+1][0]||map[y][x+1][1]))
                            return;
                    }
                    
                    if(x>0&&map[y][x-1][1]){
                        if(!map[y-1][x-1][0]&&!map[y-1][x][0]){
                            return;
                        }
                    }
                    
                    if(map[y][x+1][1]){
                        if(!map[y-1][x+1][0]&&!map[y-1][x+2][0]){
                            return;
                        }
                    }
                    map[y][x][1]=false;
                }
            }
        }
        else{//설치
            if(type==0){//기둥
                if(y==0||map[y-1][x][0]){
                    map[y][x][0]=true;
                }
                else if(map[y][x][1]||(x>0&&map[y][x-1][1])){
                    map[y][x][0]=true;
                }
            }
            else{
                if(y>0&&(map[y-1][x][0]||(x<mapSize-1)&&map[y-1][x+1][0])){
                    map[y][x][1]=true;
                }
                else if(x>0&&x<mapSize-1&&map[y][x-1][1]&&map[y][x+1][1]){
                    map[y][x][1]=true;
                }
                
            }
        }
    }
}