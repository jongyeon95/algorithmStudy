class Solution {
    public int solution(int n) {
        String s=toThree(n);
        return toTen(s);
    }
    
    public String toThree(int n){
        StringBuilder str= new StringBuilder();
        while(n>0){
            str.append(n%3);
            n/=3;
        }
        return str.toString();
    }
    
    public int toTen(String s){
        int temp=1;
        int answer=0;
        for(int i=s.length()-1; i>=0; i--){
            answer+=temp*(s.charAt(i)-'0');
            temp*=3;
        }
        return answer;
    }
}