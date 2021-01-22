import java.util.*;

class Solution {

    public class Pair {
        int y;
        int x;

        public Pair(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }

    int dy[] = {0, 0, 1, -1};
    int dx[] = {1, -1, 0, 0};
    int sizey;
    int sizex;
    boolean visited[][] = new boolean[100][100];
    int map[][];

    public void init(int y, int x) {
        sizey = y;
        sizex = x;
        for (int i = 0; i < y; i++) {
            for (int j = 0; j < x; j++) {
                visited[i][j] = false;
            }
        }
    }

    public int bfs(int y, int x, int num) {
        Queue<Pair> q = new LinkedList<Pair>();
        Pair p = new Pair(y, x);
        q.offer(p);
        int cnt = 0;

        while (!q.isEmpty()) {
            cnt++;
            p = q.poll();
            for (int i = 0; i < 4; i++) {
                int ty = p.y + dy[i];
                int tx = p.x + dx[i];
                if (ty < 0 || tx < 0 || ty >= sizey || tx >= sizex || visited[ty][tx] || map[ty][tx] != num)
                    continue;
                visited[ty][tx] = true;
                q.offer(new Pair(ty, tx));
            }
        }
        return cnt;
    }


    public int[] solution(int m, int n, int[][] picture) {
        int numberOfArea = 0;
        int maxSizeOfOneArea = 0;
        map = picture;
        init(m, n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (picture[i][j] != 0 && !visited[i][j]) {
                    visited[i][j] = true;
                    int temp = bfs(i, j, picture[i][j]);
                    if (maxSizeOfOneArea < temp)
                        maxSizeOfOneArea = temp;
                    numberOfArea++;
                }
            }
        }

        int[] answer = new int[2];
        answer[0] = numberOfArea;
        answer[1] = maxSizeOfOneArea;
        return answer;
    }
}