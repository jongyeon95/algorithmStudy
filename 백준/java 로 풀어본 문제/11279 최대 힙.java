import java.io.IOException;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
        int n=scanner.nextInt();
        PriorityQueue<Integer> q= new PriorityQueue<>(Collections.reverseOrder());
        for(int i=0; i<n; i++){
            int temp=scanner.nextInt();
            if(temp==0){
                Integer output=q.poll();
                if(output==null){
                    System.out.println(0);
                }
                else{
                    System.out.println(output);
                }
            }
            else{
                q.offer(temp);
            }
        }
    }
}