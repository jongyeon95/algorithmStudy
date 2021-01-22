import java.util.*;

class Solution {
    public String solution(String s) {
        String answer = "";
        StringBuilder str = new StringBuilder();
        str.append(s.toLowerCase());
        if (!(str.charAt(0) >= '0' && str.charAt(0) <= '9')) {
            str.setCharAt(0, Character.toUpperCase(str.charAt(0)));
        }
        for (int i = 0; i < s.length() - 1; i++) {
            char c = str.charAt(i);
            if (c == ' ') {
                if (str.charAt(i + 1) != ' ' && !(c >= '0' && c <= '9')) {
                    str.setCharAt(i + 1, Character.toUpperCase(str.charAt(i + 1)));
                }
            }

        }

        return str.toString();
    }
}