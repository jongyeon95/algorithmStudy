import java.util.*;
class Solution {
    public String solution(String s) {
        char cl[] = s.toCharArray();
        Arrays.sort(cl);
        return new StringBuilder(new String(cl)).reverse().toString();
    }
}