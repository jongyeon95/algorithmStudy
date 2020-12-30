import java.io.*; 
import java.util.*;


public class Main {
    
    public static ArrayList<ArrayList<Integer>> nodes;

    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stk = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(stk.nextToken());
        int m = Integer.parseInt(stk.nextToken());
        int indegree[]=new int[n+1];
        nodes=new ArrayList<>();
        for(int i=0; i<=n; i++){
            nodes.add(new ArrayList<Integer>());
        }

        for(int i=0; i<m; i++){
            stk= new StringTokenizer(br.readLine());
            int a=Integer.parseInt(stk.nextToken());
            int b=Integer.parseInt(stk.nextToken());
            nodes.get(a).add(b);
            indegree[b]++;
        }

        PriorityQueue<Integer> pq= new PriorityQueue<Integer>();
        
        for(int i=1; i<=n; i++){
            if(indegree[i]==0){

                pq.offer(i);
            }
        }

        StringBuffer result= new StringBuffer();
        
        while(!pq.isEmpty()){
            
            int cur=pq.poll();
            
            result.append(cur+" ");
            
            for(int i=0; i<nodes.get(cur).size(); i++){
                int next=nodes.get(cur).get(i);
                indegree[next]--;
                if(indegree[next]==0){
                    pq.offer(next);
                }
            }
            
        }
        System.out.println(result.toString());
        
   
    }

}

