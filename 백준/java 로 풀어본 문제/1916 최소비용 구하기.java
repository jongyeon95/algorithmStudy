import java.io.IOException;
import java.util.*;

class Node implements Comparable<Node> {
    int end;
    int weight;

    Node(int end, int weight) {
        this.end = end;
        this.weight = weight;
    }

    @Override
    public int compareTo(Node o) {
        return weight - o.weight;
    }
}


public class Main {
    static ArrayList<ArrayList<Node>> cities = new ArrayList<ArrayList<Node>>();
    static int[] dist;
    static boolean[] visited;
    static int city, bus;

    public static void main(String[] args) throws IOException {
        Scanner s = new Scanner(System.in);
        city = s.nextInt();
        bus = s.nextInt();

        for (int i = 0; i <= city; i++) {
            cities.add(new ArrayList<Node>());
        }
        dist = new int[city + 1];
        visited = new boolean[city + 1];
        Arrays.fill(dist, Integer.MAX_VALUE);
        for (int i = 0; i < bus; i++) {
            int a, b, c;
            a = s.nextInt();
            b = s.nextInt();
            c = s.nextInt();
            cities.get(a).add(new Node(b, c));
        }
        int start, end;
        start = s.nextInt();
        end = s.nextInt();
        System.out.println(solved(start, end));
    }

    public static int solved(int start, int end) {
        PriorityQueue<Node> pq = new PriorityQueue<Node>();
        pq.offer(new Node(start, 0));
        dist[start] = 0;
        while (!pq.isEmpty()) {
            Node temp = pq.poll();
            int cur = temp.end;
            if (!visited[cur]) {
                visited[cur] = true;
                for (Node node : cities.get(cur)) {
                    if (!visited[node.end] && dist[node.end] > dist[cur] + node.weight) {
                        dist[node.end] = dist[cur] + node.weight;
                        pq.add(new Node(node.end, dist[node.end]));
                    }
                }
            }
        }
        return dist[end];
    }
}

