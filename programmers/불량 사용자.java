import java.util.*;
class Solution {
    
    public static boolean[] visited;
    public static String[] user_id;
    public static String[] banned_id;
    public static String[] list;
    public static HashSet<String> hs;
    
    public int solution(String[] user_id, String[] banned_id) {
        visited=new boolean[user_id.length];
        this.user_id=user_id;
        this.banned_id=banned_id;
        list=new String[banned_id.length];
        hs=new HashSet<>();
        dfs(0);
        return hs.size();
    }
    
    public static void dfs(int size){
        if(size==banned_id.length){
            PriorityQueue<String> pq = new PriorityQueue<>();
            for(String temp : list)
                pq.offer(temp);
            StringBuilder sb=new StringBuilder();
            while(!pq.isEmpty()){
                sb.append(pq.poll()+" ");
            }
            hs.add(sb.toString());
            return;
        }
        for(int i=0; i<user_id.length; i++){
            if(!visited[i]){
                if(isBan(user_id[i],banned_id[size])){
                    visited[i]=true;
                    list[size]=user_id[i];
                    dfs(size+1);
                    visited[i]=false;
                }
            }
        }
        return;
    }
    
    public static boolean isBan(String user, String ban){
        if(user.length()!=ban.length())
            return false;
        for(int i=0; i<user.length(); i++){
            if(ban.charAt(i)!='*'){
                if(user.charAt(i)!=ban.charAt(i)){
                    return false;
                }
            } 
        }
        return true;
    }
}

