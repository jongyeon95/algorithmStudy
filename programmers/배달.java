import java.util.*;
public class Delivery implements Comparable<Delivery>{
    public int address;
    public int cost;
    
    public Delivery(int address, int cost){
        this.address=address;
        this.cost=cost;
    }
    
    @Override
    public int compareTo(Delivery o){
        return this.cost-o.cost;
    }
}


class Solution {
    PriorityQueue<Delivery> pq;
    ArrayList<ArrayList<Delivery>> nodes;
    int nodeCost[];
    int INF=Integer.MAX_VALUE;
    
    
    
    public int solution(int N, int[][] road, int K) {
        int answer = 0;
        pq=new PriorityQueue<>();
        nodes=new  ArrayList<ArrayList<Delivery>>();
        nodeCost=new int[N+1];
        for(int i=0; i<=N; i++){
            nodeCost[i]=INF;
        }
        for(int i=0; i<=N; i++){
            nodes.add(new ArrayList<Delivery>());
        }
        for(int i=0; i<road.length; i++){
            int a=road[i][0];
            int b=road[i][1];
            int cost=road[i][2];
            nodes.get(a).add(new Delivery(b,cost));
            nodes.get(b).add(new Delivery(a,cost));
        }
        pq.offer(new Delivery(1,0));
        nodeCost[1]=0;
        while(!pq.isEmpty()){
            Delivery start=pq.poll();
            for(Delivery to : nodes.get(start.address)){
                if(nodeCost[start.address]+to.cost<nodeCost[to.address]){
                    nodeCost[to.address]=nodeCost[start.address]+to.cost;
                    pq.offer(to);
                }
            }
            
        }
        for(int i=1; i<=N; i++){
            if(nodeCost[i]<=K)
                answer++;
        }
        
      
        return answer;
    }
}