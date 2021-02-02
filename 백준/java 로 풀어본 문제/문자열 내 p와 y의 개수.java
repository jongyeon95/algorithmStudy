class Solution {
    boolean solution(String s) {
        s=s.toLowerCase();
        if(s.replaceAll("p","").length()!=s.replaceAll("y","").length())
            return false;
        return true;
    }
}