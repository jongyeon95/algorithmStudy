import java.util.*;
import java.io.*;

public class Main
{
	
	public static HashMap<String,Pair> hm;
	public static StringBuilder sb=new StringBuilder();

	public static void main(String args[]) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int testCase=Integer.parseInt(br.readLine());
		for(int t=0; t<testCase; t++){
			int n=Integer.parseInt(br.readLine());
			hm=new HashMap<>();
			StringTokenizer stk;
			for(int i=0; i<n; i++){
				stk=new StringTokenizer(br.readLine());
				String a =stk.nextToken();
				String b =stk.nextToken();
				if(hm.get(a)==null){
					hm.put(a,new Pair(a,1));
				}
				if(hm.get(b)==null){
					hm.put(b,new Pair(b,1));
				}
				union(a,b);
				
			}

		}
		System.out.print(sb.toString());

	}

	public static String find(String s){
		if(hm.get(s).parent.equals(s)){
			return s;
		}
		hm.put(s,new Pair(find(hm.get(s).parent),hm.get(s).cnt));
		return hm.get(s).parent;
	}

	public static void union(String a, String b){
		String aa=find(a);
		String bb=find(b);
		if(aa.equals(bb)){
			sb.append(hm.get(aa).cnt+"\n");
			
			return;
		}
		Pair ap=hm.get(aa);
		Pair bp=hm.get(bb);
		ap.cnt+=bp.cnt;
		bp.parent=aa;
		hm.put(aa,ap);
		hm.put(bb,bp);
		sb.append(ap.cnt+"\n");
		return;
	}



}

class Pair{
	String parent;
	int cnt;
	public Pair(String parent, int cnt){
		this.parent=parent;
		this.cnt=cnt;
	}
}
