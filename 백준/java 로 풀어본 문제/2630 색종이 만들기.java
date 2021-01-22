import java.io.*;
import java.util.*;


public class Main {
    public static int map[][];
    public static boolean visited[][];
    public static int bluePaper;
    public static int whitePaper;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer stk;
        map = new int[n][n];
        visited = new boolean[n][n];
        bluePaper = 0;
        whitePaper = 0;
        for (int i = 0; i < n; i++) {
            stk = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                map[i][j] = Integer.parseInt(stk.nextToken());
            }
        }
        int size = n;
        while (size > 0) {
            for (int i = 0; i < n; i += size) {
                for (int j = 0; j < n; j += size) {
                    findSq(i, j, size);
                }
            }
            size /= 2;
        }

        System.out.println(whitePaper);
        System.out.println(bluePaper);

    }

    public static void findSq(int y, int x, int size) {
        boolean check = true;
        for (int i = y; i < y + size; i++) {
            for (int j = x; j < x + size; j++) {
                if (map[i][j] == 0 || visited[i][j]) {
                    check = false;
                    break;
                }
            }
            if (!check)
                break;
        }
        if (!check) {
            check = true;
            for (int i = y; i < y + size; i++) {
                for (int j = x; j < x + size; j++) {
                    if (map[i][j] == 1 || visited[i][j]) {
                        check = false;
                        break;
                    }
                    if (!check)
                        break;
                }
            }
        } else {
            bluePaper++;
            for (int i = y; i < y + size; i++) {
                for (int j = x; j < x + size; j++) {
                    visited[i][j] = true;
                }
            }
            return;
        }

        if (check) {
            whitePaper++;
            for (int i = y; i < y + size; i++) {
                for (int j = x; j < x + size; j++) {
                    visited[i][j] = true;
                }
            }
        }
    }

}

