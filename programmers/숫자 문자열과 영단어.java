class Solution {
    public int solution(String s) {
        int answer = 0;
        String result=s;
        result=result.replaceAll("zero","0");
        result=result.replaceAll("one","1");
        result=result.replaceAll("two","2");
        result=result.replaceAll("three","3");
        result=result.replaceAll("four","4");
        result=result.replaceAll("five","5");
        result=result.replaceAll("six","6");
        result=result.replaceAll("seven","7");
        result=result.replaceAll("eight","8");
        result=result.replaceAll("nine","9");
        answer=Integer.parseInt(result);
        return answer;
    }
}