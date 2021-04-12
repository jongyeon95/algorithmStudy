import java.io.*;
import java.util.*;

public class Main{
	public static int n;
	public static int[] list;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n=Integer.parseInt(br.readLine());
		StringTokenizer stk= new StringTokenizer(br.readLine());
		TreeSet<Integer> ts= new TreeSet<Integer>();
		HashMap<Integer,Integer> hm=new HashMap<Integer,Integer>();
		list=new int[n];
		for(int i=0; i<n; i++){
			list[i]=Integer.parseInt(stk.nextToken());
			if(hm.get(list[i])==null){
				hm.put(list[i],0);
				ts.add(list[i]);
			}
		}
		int cnt=0;
		for(Integer temp : ts){
			hm.put(temp,cnt);
			cnt++;
		}
		StringBuilder sb = new StringBuilder();
		for(int temp : list){
			sb.append(hm.get(temp)+" ");
		}
		System.out.print(sb.toString());
	}
}

