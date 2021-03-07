import java.util.*;
import java.io.*;

public class Main{
	
	public static void main(String[] arg) throws IOException{
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int N = Integer.parseInt(st.nextToken());
        int L = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine(), " ");

        ArrayDeque<Integer> deque = new ArrayDeque<>();
        int val[] = new int[N];

        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < N; i++) {
            val[i] = Integer.parseInt(st.nextToken());

            while(!deque.isEmpty() && val[deque.peekLast()] > val[i]) deque.pollLast();
            deque.offer(i);

            if(i-deque.peekFirst() >= L) deque.pollFirst();
            sb.append(val[deque.peekFirst()]);
            sb.append(" ");
        }

        bw.write(sb.toString());
        bw.close();
    
	}
}