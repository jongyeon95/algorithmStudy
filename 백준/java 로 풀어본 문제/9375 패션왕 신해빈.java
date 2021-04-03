import java.util.*;
import java.io.*;

public class Main{
	public static int answer;
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer stk;
		int testcase=Integer.parseInt(br.readLine());
		for(int t=0; t<testcase; t++){
			answer=1;
			int n=Integer.parseInt(br.readLine());
			if(n==0){
				System.out.println(0);
				continue;
			}
			HashMap<String,Integer> hm= new HashMap<>();
			for(int i=0; i<n; i++){
				stk=new StringTokenizer(br.readLine());
				stk.nextToken();
				String input=stk.nextToken();
				if(hm.get(input)==null){
					hm.put(input,1);
				}
				else{
					hm.put(input,hm.get(input)+1);
				}
			}

			
			hm.values().forEach((value)->answer=answer*(value+1));
			answer--;
			System.out.println(answer);



		}
	}
}