import java.util.*;
import java.io.*;

public class Main {

    public static String inputs[];
    public static boolean isUsed[]=new boolean[26];
    public static int k;
    public static int n;
    public static int answer;
   
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stk = new StringTokenizer(br.readLine());
        n=Integer.parseInt(stk.nextToken());
        k=Integer.parseInt(stk.nextToken());
        inputs=new String[n];
        for (int i=0; i<n; i++) {
            String temp =br.readLine();
            inputs[i]=temp.replaceAll("[acnti]","");
            
        }
        isUsed['a'-'a']=true;
        isUsed['c'-'a']=true;
        isUsed['n'-'a']=true;
        isUsed['t'-'a']=true;
        isUsed['i'-'a']=true;
        if(k>4)
            dfs(5,0);
        System.out.println(answer);
            
       
    }

    public static void dfs(int cnt, int index){
        if(cnt>=k){
            solve();
            return;
        }
        for(int i=index; i<26; i++){
            if(!isUsed[i]){
                isUsed[i]=true;
                dfs(cnt+1,i);
                isUsed[i]=false;
            }
        }
    }

    public static void solve(){
     
        int result=0;
        for(int i=0; i<n; i++){
            boolean check=true;
            for(int j=0; j<inputs[i].length(); j++){
                if(!isUsed[inputs[i].charAt(j)-'a']){
                    check=false;
                    break;
                }
            }
            if(check)
                result++;
        }
        if(result>answer)
            answer=result;
        return;
    }


}