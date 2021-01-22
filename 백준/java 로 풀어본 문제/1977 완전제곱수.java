import java.io.IOException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner s = new Scanner(System.in);
        int[] square = new int[101];
        int m = s.nextInt();
        int n = s.nextInt();
        int result = -1;
        int minNum = 0;
        boolean check = false;
        for (int i = 1; i <= 100; i++) {
            if (i * i >= m && i * i <= n) {
                if (!check) {
                    check = true;
                    result = i * i;
                    minNum = i * i;
                } else {
                    result += i * i;
                }
            }
        }
        System.out.println(result);
        if (check) {
            System.out.println(minNum);
        }

    }
}

