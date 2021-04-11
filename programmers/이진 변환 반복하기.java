class Solution {
    public int[] solution(String s) {
        int[] answer = {0,0};
        String input=s;
        while(true){
            if(input.equals("1"))
                return answer;
            String temp=input.replaceAll("0","");
            answer[0]++;
            answer[1]+=input.length()-temp.length();
            int num=temp.length();
            StringBuilder sb= new StringBuilder();
            while(num>0){
                sb.append(num%2);
                num/=2;
            }
            input=sb.toString();
        }
    }
}