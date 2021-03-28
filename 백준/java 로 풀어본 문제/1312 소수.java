import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int A = Integer.parseInt(st.nextToken());
        int B = Integer.parseInt(st.nextToken());
        int N = Integer.parseInt(st.nextToken());
        A %= B;
        for (int i = 0; i < N - 1; i++) {
            A *= 10;
            A %= B;
        }
        A *= 10;
        bw.write(A / B + "\n");

        bw.flush();
        br.close();
        bw.close();
    }
}