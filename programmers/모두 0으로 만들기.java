import java.util.*;
class Solution {
    public static ArrayList<Node> list;
    public static ArrayList<ArrayList<Integer>> map;
    public long solution(int[] a, int[][] edges) {
        long answer = -1;
        list=new ArrayList<Node>();
        map=new ArrayList<>();  
        for(int i=0; i<a.length; i++){
            list.add(new Node(0,Long.valueOf(a[i])));
            map.add(new ArrayList<>());        
        }
        for(int i=0; i<edges.length; i++){
            int b=edges[i][0];
            int c=edges[i][1];
            map.get(b).add(c);
            map.get(c).add(b);
            list.get(b).edge++;
            list.get(c).edge++;
        }
        
        Queue<Integer> q = new LinkedList<>();
        for(int i=0; i<a.length; i++){
            if(list.get(i).edge==1)
                q.offer(i);
        }
        Long cnt=0L;
        while(!q.isEmpty()){
            int index=q.poll();
            if(list.get(index).edge==0)
                continue;
            list.get(index).edge--;
            for(int i=0; i<map.get(index).size();i++){
                int temp =map.get(index).get(i);
                if(list.get(temp).edge>0){
                    list.get(temp).edge--;
                    
                    list.get(temp).weight+=list.get(index).weight;
                    
                    cnt+=Math.abs(list.get(index).weight);
                    list.get(index).weight=0L;
                    if(list.get(temp).edge==1)
                        q.offer(temp);
                    
                    break;
                }
            }
        }
       
        for(int i=0; i<list.size(); i++){
          
            if(list.get(i).weight!=0){
                
                return -1;
            }
            
        }
        return cnt;
        
    }
}
class Node{
    int edge;
    Long weight;
    public Node(int edge , Long weight){
        this.edge=edge;
        this.weight=weight;
    }
}