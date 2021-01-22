import java.io.*;
import java.util.*;


public class Main {

    static int size, count;
    static int[] students;
    static int[] check;
    static int[] cycle;


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int total = sc.nextInt();
        for (int i = 0; i < total; i++) {

            int size = sc.nextInt();

            students = new int[size + 1];
            check = new int[size + 1];
            cycle = new int[size + 1];

            for (int j = 1; j <= size; j++) {
                students[j] = sc.nextInt();
            }

            count = 0;
            for (int p = 1; p <= size; p++) {
                if (check[p] != 0) {
                    continue;
                }
                if (check[students[p]] == 0) {
                    count += dfs(p, p, 1);
                }
            }

            int result = size - count;
            System.out.println(result);
        }
    }

    private static int dfs(int start, int num, int level) {

        check[num] = level;
        cycle[num] = start;


        int next = students[num];

        if (check[next] != 0 && start == cycle[next]) {
            return level - check[next] + 1;
        } else if (check[next] != 0 && start != cycle[next]) {
            return 0;
        }
        return dfs(start, next, level + 1);

    }
}

