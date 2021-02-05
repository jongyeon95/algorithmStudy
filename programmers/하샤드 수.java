class Solution {
    public boolean solution(int x) {
        boolean answer = true;
        int num=x;
        int sumNum=0;
        while(num>0){
            sumNum+=num%10;
            num/=10;
        }
        if(x%sumNum!=0)
            answer=false;
        return answer;
    }
}