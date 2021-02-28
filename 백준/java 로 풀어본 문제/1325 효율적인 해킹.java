import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;
 
public class Main {
 
    static int N, M;
    static int[] vertex;
    static int[] nodeMap;
    static int[] ans;
    static int result;
    static ArrayList<Integer>[] list = new ArrayList[10001];
 
    public static void main(String[] args) throws IOException {
        // TODO Auto-generated method stub
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
 
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        result = 0;
        nodeMap = new int[10001];
        ans = new int[10001];
 
        for (int i = 1; i <= N; i++) {
            list[i] = new ArrayList<>();
        }
 
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine(), " ");
 
            int n1 = Integer.parseInt(st.nextToken());
            int n2 = Integer.parseInt(st.nextToken());
 
            list[n1].add(n2);
            nodeMap[n1] = n2;
        }
 
        for (int i = 1; i <= N; i++) {
            vertex = new int[100001];
            dfs(i);
        }
 
        for (int i = 1; i <= N; i++) {
            if (result == ans[i]) {
                System.out.print(i + " ");
            }
        }
 
    }
 
    static void dfs(int node) {
 
        vertex[node] = 1;
 
        for (int i : list[node]) {
 
            if (vertex[i] == 0) {
                ans[i] += 1;
                result = Math.max(result, ans[i]);
                dfs(i);
            }
        }
 
    }
}
