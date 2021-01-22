import java.util.*;

class Solution {
    boolean visited[];
    int[][] computers;

    public void bfs(int node) {
        Queue<Integer> q = new LinkedList<>();
        q.offer(node);
        while (!q.isEmpty()) {
            int a = q.poll();
            for (int i = 0; i < visited.length; i++) {
                if (!visited[i] && computers[a][i] == 1) {
                    visited[i] = true;
                    q.offer(i);
                }
            }
        }
    }

    public int solution(int n, int[][] computers) {
        visited = new boolean[n];
        int answer = 0;
        this.computers = computers;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                visited[i] = true;
                bfs(i);
                answer++;
            }
        }


        return answer;
    }
}