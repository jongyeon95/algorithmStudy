import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n=Integer.parseInt(br.readLine());
        int answer=0;
        PriorityQueue<Integer> pq= new PriorityQueue<>();
        for(int i=0; i<n; i++){
            pq.offer(Integer.parseInt(br.readLine()));
        }
        while(!pq.isEmpty()){
            int temp=0;
            temp+=pq.poll();
            if(pq.isEmpty()){
                break;
            }
            temp+=pq.poll();
            answer += temp;
            pq.offer(temp);
        }
        System.out.println(answer);
    }
}