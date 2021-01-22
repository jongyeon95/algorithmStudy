import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer stk = new StringTokenizer(br.readLine());
        HashSet<Integer> hs = new HashSet<>();
        for (int i = 0; i < n; i++) {
            hs.add(Integer.valueOf(stk.nextToken()));
        }
        System.out.println(n - hs.size());


    }

}

