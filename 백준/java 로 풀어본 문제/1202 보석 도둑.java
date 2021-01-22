import java.io.*;
import java.util.*;


class Jewelry implements Comparable<Jewelry> {
    int weight;
    int value;

    public Jewelry(int w, int v) {
        this.weight = w;
        this.value = v;
    }

    @Override
    public int compareTo(Jewelry o) {
        return this.weight - o.weight;
    }
}


public class Main {


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stk = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(stk.nextToken());
        int k = Integer.parseInt(stk.nextToken());
        PriorityQueue<Jewelry> pq = new PriorityQueue<>();
        PriorityQueue<Integer> bpq = new PriorityQueue<>();
        long answer = 0;
        for (int i = 0; i < n; i++) {
            stk = new StringTokenizer(br.readLine());
            int weight = Integer.parseInt(stk.nextToken());
            int value = Integer.parseInt(stk.nextToken());
            pq.offer(new Jewelry(weight, value));
        }
        for (int i = 0; i < k; i++) {
            bpq.offer(Integer.parseInt(br.readLine()));
        }
        PriorityQueue<Integer> q = new PriorityQueue<>();
        while (!bpq.isEmpty()) {
            int bagSize = bpq.poll();
            while (!pq.isEmpty()) {
                Jewelry j = pq.poll();
                if (j.weight > bagSize) {
                    pq.offer(j);
                    break;
                } else {
                    q.offer(j.value * -1);
                }
            }
            if (!q.isEmpty())
                answer += q.poll();
        }
        System.out.println(answer * -1);

    }

}

