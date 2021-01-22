import java.util.*;
import java.io.*;


public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int testcase = Integer.parseInt(br.readLine());
        while (testcase-- > 0) {
            String[] command = new String[10000];
            boolean[] visited = new boolean[10000];
            StringTokenizer stk = new StringTokenizer(br.readLine());
            int fromStr = Integer.parseInt(stk.nextToken());
            int toStr = Integer.parseInt(stk.nextToken());
            Queue<Integer> q = new LinkedList<>();
            visited[fromStr] = true;
            q.add(fromStr);
            Arrays.fill(command, "");
            while (!q.isEmpty() && !visited[toStr]) {
                int now = q.poll();
                int D = (2 * now) % 10000;
                int S = (now == 0) ? 9999 : now - 1;
                int L = (now % 1000) * 10 + now / 1000;
                int R = (now % 10) * 1000 + now / 10;

                if (!visited[D]) {
                    q.add(D);
                    visited[D] = true;
                    command[D] = command[now] + "D";
                }

                if (!visited[S]) {
                    q.add(S);
                    visited[S] = true;
                    command[S] = command[now] + "S";
                }
                if (!visited[L]) {
                    q.add(L);
                    visited[L] = true;
                    command[L] = command[now] + "L";
                }
                if (!visited[R]) {
                    q.add(R);
                    visited[R] = true;
                    command[R] = command[now] + "R";
                }
            }
            System.out.println(command[toStr]);
        }

    }


}