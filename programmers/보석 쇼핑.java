import java.util.*;

class Solution {
    public int[] solution(String[] gems) {
        int[] answer = {0,0};
        int maxLength=gems.length+1;
        HashSet<String> hs= new HashSet<>();
        HashMap<String,Integer> hm=new HashMap<>();
        Queue<String> q=new LinkedList<>();
        for(String temp : gems)
            hs.add(temp);
        int size=hs.size();
        for(int i=0; i<gems.length+1;){
            if(hm.size()<size){
                if(i==gems.length)
                    break;
                q.offer(gems[i]);
                if(hm.get(gems[i])==null){
                    hm.put(gems[i],1);
                }
                else{
                    hm.put(gems[i],hm.get(gems[i])+1);
                }
                i++;
            }
            else{
                if(q.size()<maxLength){
                    maxLength=q.size();
                    answer[0]=i-q.size()+1;
                    answer[1]=i;
                }
                String temp=q.poll();
                if(hm.get(temp)==1){
                    hm.remove(temp);
                }
                else{
                    hm.put(temp,hm.get(temp)-1);
                }
            }
        }
        
        return answer;
    }
}