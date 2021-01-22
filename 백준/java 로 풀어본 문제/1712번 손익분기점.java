import java.io.IOException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner s = new Scanner(System.in);
        int a = s.nextInt();
        int b = s.nextInt();
        int c = s.nextInt();
        if (b >= c) {
            System.out.println(-1);
            return;
        } else {
            System.out.println(a / (c - b) + 1);
        }
    }
}

