import java.io.*;
import java.util.*;

public class Main {
    public static void main(String arg[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stk = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(stk.nextToken());
        int k = Integer.parseInt(stk.nextToken());
        int arr[] = new int[k];
        stk = new StringTokenizer(br.readLine());
        for (int i = 0; i < k; i++) {
            arr[i] = Integer.parseInt(stk.nextToken());
        }
        int result = 0;
        ArrayList<Integer> list = new ArrayList<>();
        for (int i = 0; i < k; i++) {

            if (list.contains(arr[i])) {
                continue;
            }
            if (list.size() < n) {
                list.add(arr[i]);
            } else {
                result++;
                int check[] = new int[n];
                for (int j = i; j < k; j++) {
                    if (list.contains(arr[j])) {
                        if (check[list.indexOf(arr[j])] == 0)
                            check[list.indexOf(arr[j])] = j;
                    }
                }
                int ccheck = -1;
                for (int j = 0; j < n; j++) {
                    if (check[j] == 0) {
                        ccheck = j;
                        break;
                    }
                }
                if (ccheck != -1) {

                    list.set(ccheck, arr[i]);
                } else {
                    int maxIndex = 0;
                    int maxValue = 0;
                    for (int j = 0; j < n; j++) {
                        if (check[j] >= maxValue) {
                            maxValue = check[j];
                            maxIndex = j;
                        }
                    }

                    list.set(maxIndex, arr[i]);
                }

            }
        }
        System.out.println(result);


    }
}