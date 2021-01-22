import java.io.*;
import java.util.*;

class Node implements Comparable<Node> {

    int y;
    int x;
    int cnt;

    Node(int y, int x, int cnt) {
        this.y = y;
        this.x = x;
        this.cnt = cnt;
    }

    @Override
    public int compareTo(Node o) {
        return this.cnt - o.cnt;
    }

}


public class Main {
    static int n;
    static int m;
    static int[][] room;


    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stk = new StringTokenizer(bf.readLine());
        m = Integer.parseInt(stk.nextToken());
        n = Integer.parseInt(stk.nextToken());
        room = new int[n][m];
        for (int i = 0; i < n; i++) {
            String input = bf.readLine();
            for (int j = 0; j < m; j++) {
                room[i][j] = input.charAt(j) - '0';
            }
        }
        System.out.println(solved());

    }

    public static int solved() {
        PriorityQueue<Node> pq = new PriorityQueue<>();
        int dy[] = {0, 0, 1, -1};
        int dx[] = {1, -1, 0, 0};
        boolean visited[][] = new boolean[n][m];
        visited[0][0] = true;
        pq.offer(new Node(0, 0, 0));
        while (!pq.isEmpty()) {
            Node temp = pq.poll();
            if (temp.y == n - 1 && temp.x == m - 1) {
                return temp.cnt;
            }
            for (int i = 0; i < 4; i++) {
                int ty = temp.y + dy[i];
                int tx = temp.x + dx[i];
                if (ty < 0 || tx < 0 || ty >= n || tx >= m)
                    continue;
                if (!visited[ty][tx] && room[ty][tx] == 0) {
                    visited[ty][tx] = true;
                    pq.offer(new Node(ty, tx, temp.cnt));
                }
                if (!visited[ty][tx] && room[ty][tx] == 1) {
                    visited[ty][tx] = true;
                    pq.offer(new Node(ty, tx, temp.cnt + 1));
                }

            }

        }
        return 0;
    }

}

