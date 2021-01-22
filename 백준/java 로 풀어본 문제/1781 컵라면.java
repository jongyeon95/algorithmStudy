import java.io.*;
import java.util.*;

class Question implements Comparable<Question> {

    int deadline;

    int ramen;

    public Question(int deadline, int ramen) {
        this.deadline = deadline;
        this.ramen = ramen;
    }

    @Override
    public int compareTo(Question o) {
        if (this.deadline == o.deadline) {
            return this.ramen - o.ramen;
        }
        return this.deadline - o.deadline;

    }

}


public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer stk;
        PriorityQueue<Question> pq = new PriorityQueue<>();

        for (int i = 0; i < n; i++) {
            stk = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(stk.nextToken());
            int b = Integer.parseInt(stk.nextToken());
            pq.offer(new Question(a, b));
        }
        int time = 1;
        int result = 0;
        PriorityQueue<Integer> q = new PriorityQueue<>();
        while (!pq.isEmpty()) {
            while (!pq.isEmpty()) {
                Question temp = pq.poll();
                if (temp.deadline <= time) {
                    q.offer(temp.ramen);
                } else {
                    pq.offer(temp);
                    break;
                }
            }
            while (q.size() > time) {
                q.poll();
            }
            time++;
        }
        while (!q.isEmpty()) {
            result += q.poll();
        }
        System.out.println(result);

    }

}

