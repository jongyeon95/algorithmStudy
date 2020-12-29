import java.io.*; 
import java.util.*;

class Num implements Comparable<Num>{
    int index;
    int value;

    public Num(int i, int v){
        this.index=i;
        this.value=v;
    }

    @Override
    public int compareTo(Num o){
        return o.value-this.value;
    }

}

public class Main {
    

    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        int n=Integer.parseInt(br.readLine());
        StringTokenizer stk = new StringTokenizer(br.readLine());
        ArrayList<Integer> arr=new ArrayList<>();
        for (int i=0; i<n; i++) {
            arr.add(Integer.parseInt(stk.nextToken()));
        }
        int s=Integer.parseInt(br.readLine());
        int start=0;
        while(start<n){
            
            PriorityQueue<Num> pq=new PriorityQueue<>();
            for(int i=start+1; i<n; i++){
                if(arr.get(i)>arr.get(start)&&s-(i-start)>=0){
                    pq.offer(new Num(i,arr.get(i)));
                }
            }

            if(!pq.isEmpty()){
                Num temp=pq.poll();
                s-=temp.index-start;
                arr.remove(temp.index);
                arr.add(start,temp.value);
            }
            start++;
        
        }
        for(int i=0; i<n; i++){
            System.out.print(arr.get(i)+" ");
        }
   
    }

}

