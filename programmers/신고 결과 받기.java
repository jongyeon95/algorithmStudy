import java.util.*;

class Solution {
    public int[] solution(String[] id_list, String[] report, int k) {
        int[] answer = new int[id_list.length];
        HashMap<String,Integer> id_hash = new HashMap<String,Integer>();
        HashMap<String,Integer> result_hash = new HashMap<String,Integer>();
        ArrayList<Set<String>> report_list = new ArrayList<>();
        
        
        //init
        for(int i=0; i<id_list.length; i++){
            id_hash.put(id_list[i],i);
            report_list.add(new HashSet<String>());
            
        }
        
        for(int i=0; i<report.length; i++){
            String[] temp = report[i].split(" ");
            report_list.get(id_hash.get(temp[0])).add(temp[1]);
        }
        
        for(int i=0; i<id_list.length; i++){
            Iterator<String> it = report_list.get(i).iterator();
            while (it.hasNext()) { 
                String temp = it.next();
                if(result_hash.containsKey(temp)){
                    result_hash.put(temp,result_hash.get(temp)+1);
                }
                else{
                    result_hash.put(temp,1);
                }
            }
            
        }
        for(int i=0; i<id_list.length; i++){
            Iterator<String> it = report_list.get(i).iterator();
            int cnt=0;
            while (it.hasNext()) { 
                String temp = it.next();
                if(result_hash.containsKey(temp)&&result_hash.get(temp)>=k){
                   cnt++;
                }
            }
            answer[i]=cnt;
        }
        
        
        return answer;
    }
}