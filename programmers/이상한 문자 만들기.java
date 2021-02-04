class Solution {
    public String solution(String s) {
        String answer = "";
        StringBuilder sb= new StringBuilder(s.toLowerCase());
        int cnt=0;
        for(int i=0; i<s.length();i++){
            if(sb.charAt(i)==' '){
                cnt=0;
                continue;
            }
            if(cnt%2==0){
                sb.setCharAt(i,(char)(sb.charAt(i)-32));
            }
             cnt++;
        }
        return sb.toString();
    }
}