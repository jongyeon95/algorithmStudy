import java.util.*;

class Pair implements Comparable<Pair>{
    String s;
    int cnt;
    
    public Pair(String s, int cnt){
        this.s=s;
        this.cnt=cnt;
    }
    
    @Override
    public int compareTo(Pair o){
        return o.cnt-this.cnt;
    }
}

class Solution {
    public static HashMap<String,Integer> hm = new  HashMap<>();
    public static List<String> list = new ArrayList<String>();
    public static List<ArrayList<Pair>> plist = new ArrayList<>();
    public String[] solution(String[] orders, int[] course) {
        String[] answer = {};
        
        for(int i=0; i<orders.length; i++){
            char[] c=orders[i].toCharArray();
            Arrays.sort(c);
            dfs(0,c,"");
        }
        
        for(int i=0; i<=20; i++){
            plist.add(new ArrayList<Pair>());
        }
        
        for(String key : hm.keySet()){
            if(hm.get(key)>1){
                plist.get(key.length()).add(new Pair(key,hm.get(key)));
            }
        }
        
        for(int i=0; i<course.length; i++){
            int temp=course[i];
            Collections.sort(plist.get(temp));
            for(int j=0; j<plist.get(temp).size(); j++){
                list.add(plist.get(temp).get(j).s);
                if(j+1>=plist.get(temp).size()
                   ||plist.get(temp).get(j).cnt!=plist.get(temp).get(j+1).cnt)
                    break;
            }
        }
        Collections.sort(list);
       
        return list.toArray(new String[list.size()]);
    }
    
    public static void dfs(int index , char[] input, String result){
        for(int i=index; i<input.length; i++){
            String temp = result+input[i];
            if(temp.length()>1){
                if(hm.get(temp)==null){
                    hm.put(temp,1);
                }
                else{
                    hm.put(temp,hm.get(temp)+1);
                }
            }
            dfs(i+1,input,temp);
        }
    }
}