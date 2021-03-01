import java.util.*;
import java.io.*;

public class Main{
	public static void main(String[] arg) throws IOException{
		BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer stk = new StringTokenizer(br.readLine());
		int n=Integer.parseInt(stk.nextToken());
		int m=Integer.parseInt(stk.nextToken());
		List<Integer> list = new ArrayList<Integer>();
		HashMap<Integer,Integer> hm = new HashMap<>();
		for(int i=0; i<n; i++){
			list.add(Integer.parseInt(br.readLine()));
		}
		Collections.sort(list);
		StringBuilder sb= new StringBuilder();
		for(int i=0; i<n; i++){
			if(hm.get(list.get(i))==null){
				hm.put(list.get(i),i);
			}
		}
		for(int i=0; i<m; i++){
			int temp=Integer.parseInt(br.readLine());
			if(hm.get(temp)==null){
				sb.append("-1\n");
			}
			else{
				sb.append(hm.get(temp)+"\n");
			}
		}
		System.out.print(sb.toString());

	}
}