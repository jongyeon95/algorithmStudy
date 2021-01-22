
import java.util.Scanner;
import java.io.FileInputStream;

class Solution {
    public static void main(String args[]) throws Exception {
        Scanner sc = new Scanner(System.in);
        int T;
        T = sc.nextInt();
        for (int test_case = 1; test_case <= T; test_case++) {
            String s = sc.next();
            int L = 2;
            while (true) {
                Boolean check = true;
                for (int i = 0; i < 30 - L; i++) {
                    if (s.charAt(i) != s.charAt(i + L)) {
                        check = false;
                        break;
                    }
                }
                if (check) {
                    System.out.println("#" + test_case + " " + L);
                    break;
                } else
                    L++;
            }

        }
    }
}