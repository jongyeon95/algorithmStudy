import java.util.*;
class Solution {
    public int[] solution(int n, String[] words) {
        int[] answer = {0,0};
        HashMap hm= new HashMap<String,Boolean>();
        int cnt=1;
        int pCnt=1;
        for(int i=0; i<words.length; i++){
            
            if(hm.get(words[i])!=null
               ||(i!=0 && words[i].charAt(0)!=words[i-1].charAt(words[i-1].length()-1))){
                answer[0]=cnt;
                answer[1]=pCnt;
                return answer;
            }
            else{
                hm.put(words[i],true);
            }
            cnt++;
            if(cnt>n){
                cnt=1;
                pCnt++;
            }
        }
       

        
        return answer;
    }
}