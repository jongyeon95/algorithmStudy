import java.util.*;
import java.lang.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        PriorityQueue<Integer> pq = new PriorityQueue<Integer>(new Comparator<Integer>() {

            public int compare(Integer a, Integer b) {
                if (Math.abs(a) == Math.abs(b))
                    return a - b;
                return Math.abs(a) - Math.abs(b);
            }
        });
        while (n-- > 0) {
            int temp = s.nextInt();
            if (temp == 0) {
                if (!pq.isEmpty()) {
                    System.out.println(pq.poll());
                } else {
                    System.out.println(0);
                }
            } else {
                pq.offer(temp);
            }
        }

    }
}

