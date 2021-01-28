import java.util.*;
class Pair implements Comparable<Pair>{
    String key;
    int value;
    public Pair(String key, int value){
        this.key=key;
        this.value=value;
    }
    
    @Override
    public int compareTo(Pair o){
        return o.value-this.value;
    }
}

class Solution {
    public int[] solution(String s) {
        int[] answer;
        String input=s.substring(2,s.length()-2);
        String[] str=input.split("\\}\\,\\{|\\,");
        HashMap<String,Integer> hm = new HashMap<>();
        for(String temp : str){
           if(hm.get(temp)==null){
               hm.put(temp,1);
           }
            else
                hm.put(temp,hm.get(temp)+1);
        }
        ArrayList<Pair> list = new ArrayList<>();
        hm.forEach((k,v)->list.add(new Pair(k,v)));
        Collections.sort(list);
        answer=new int[list.size()];
        for(int i=0; i<list.size(); i++){
            answer[i]=Integer.parseInt(list.get(i).key);
        }
        return answer;
    }
}