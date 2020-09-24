import java.util.*;
class Solution {
    public class Pair{
        int index;
        int count;
        
        Pair(int i, int c){
            this.index=i;
            this.count=c;
        }
    }
    
    boolean visited[];
    ArrayList<ArrayList<Integer>> list;
    int answer;
    int answerSize;
    
    public void bfs(){
        visited[1]=true;
        Queue<Pair> q= new LinkedList<Pair>();
        q.offer(new Pair(1,1));
        while(!q.isEmpty()){
            Pair p=q.poll();
            if(p.count>answerSize){
                answerSize=p.count;
                answer=1;
            }
            else if(p.count==answerSize){
                answer++;
            }
            for(int i=0; i<list.get(p.index).size(); i++){
                if(!visited[list.get(p.index).get(i)]){
                    visited[list.get(p.index).get(i)]=true;
                    q.offer(new Pair(list.get(p.index).get(i),p.count+1));
                }
            }
        }
        
        
    }
    
    
    public int solution(int n, int[][] edge) {
        answer = 0;
        answerSize=0;
        list=new ArrayList<ArrayList<Integer>>();
        visited=new boolean[n+1];
        for(int i=0; i<n+1; i++){
            visited[i]=false;
            list.add(new ArrayList<Integer>());
        }
        for(int i=0; i<edge.length; i++){
            list.get(edge[i][0]).add(edge[i][1]);
            list.get(edge[i][1]).add(edge[i][0]);
        }
        bfs();
        return answer;
    }
}