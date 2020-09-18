class Solution {
    public int solution(String s) {
        int answer = 10000;
        if(s.length()==1)
            return 1;
        for(int i=0;i<=s.length()/2; i++){
            String temp=s.substring(0,i+1);
            String result="";
            int cnt=1;
            for(int j=i+1; j<s.length(); j+=i+1){
                if(result.length()>answer)
                    break;
                
                if(j+i+1<s.length()&&s.substring(j,j+i+1).equals(temp)){
                    cnt++;
                }
                else if(j+i+1<s.length()){
                    if(cnt>1){
                        result+=Integer.toString(cnt);
                    }
                    result+=temp;
                    temp=s.substring(j,j+i+1);
                    cnt=1;       
                }
                else{
                    if(!temp.equals(s.substring(j))){
                        result+=s.substring(j);
                    }
                    else{
                        cnt++;
                    }
                    if(cnt>1){
                        result+=Integer.toString(cnt);
                    }
                    result+=temp;
                }
            }
            if(result.length()<answer){
                answer=result.length();
            }
        }
        return answer;
    }
}