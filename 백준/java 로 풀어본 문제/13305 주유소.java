import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer stk = new StringTokenizer(br.readLine());
        int road[] = new int[n - 1];
        int cost[] = new int[n];
        long result = 0L;
        for (int i = 0; i < n - 1; i++) {
            road[i] = Integer.parseInt(stk.nextToken());
        }
        stk = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            cost[i] = Integer.parseInt(stk.nextToken());
        }
        int end = 0;
        int start = 0;
        int oil = cost[0];
        while (end < n) {
            if (oil > cost[end]) {
                Long roadLength = 0L;
                for (int i = start; i < end; i++) {
                    roadLength += road[i];
                }
                start = end;
                result += oil * roadLength;
                oil = cost[end];
            }
            end++;
        }
        Long roadLength = 0L;
        for (int i = start; i < n - 1; i++) {
            roadLength += road[i];
        }
        result += oil * roadLength;
        System.out.println(result);
    }
}