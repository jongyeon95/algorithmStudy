import java.io.*;
import java.util.*;


public class Main {
    public static StringBuffer n;

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int alpha[] = new int[26];
        int max = 0;
        while (sc.hasNextLine()) {
            String line = sc.nextLine();
            for (int i = 0; i < line.length(); i++) {
                if (line.charAt(i) != ' ') {
                    alpha[line.charAt(i) - 'a']++;
                    if (max < alpha[line.charAt(i) - 'a']) {
                        max = alpha[line.charAt(i) - 'a'];
                    }
                }
            }
        }
        for (int i = 0; i < 26; i++) {
            if (alpha[i] == max) System.out.print((char) (i + 'a'));
        }

    }


}

