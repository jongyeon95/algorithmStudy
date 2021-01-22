import java.io.IOException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner s = new Scanner(System.in);
        int testcase = s.nextInt();
        while (testcase > 0) {
            int h, w, n;
            h = s.nextInt();
            w = s.nextInt();
            n = s.nextInt();
            n--;
            System.out.println((n / h + 1) + ((n % h + 1) * 100));
            testcase--;
        }
    }
}