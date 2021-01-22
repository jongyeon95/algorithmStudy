import java.io.*;
import java.util.*;

public class Main {

    public static void main(String arg[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int testcase = Integer.parseInt(br.readLine());
        StringBuffer sb = new StringBuffer();
        while (testcase-- > 0) {
            StringTokenizer stk = new StringTokenizer(br.readLine());
            int shipNum = Integer.parseInt(stk.nextToken());
            int dist = Integer.parseInt(stk.nextToken());
            int answer = 0;
            while (shipNum-- > 0) {
                stk = new StringTokenizer(br.readLine());
                int v = Integer.parseInt(stk.nextToken());
                int f = Integer.parseInt(stk.nextToken());
                int c = Integer.parseInt(stk.nextToken());
                long canDist = v * f / c;
                if (canDist >= dist) {
                    answer++;
                }
            }
            sb.append(answer + "\n");
        }
        System.out.print(sb.toString());
    }

}