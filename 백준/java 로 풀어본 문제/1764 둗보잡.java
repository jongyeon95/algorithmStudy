import java.util.*;
import java.io.*;

public class Main{

	public static void main(String arg[]) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer stk = new StringTokenizer(br.readLine());
		int a=Integer.parseInt(stk.nextToken());
		int b=Integer.parseInt(stk.nextToken());
		List<String> answer = new ArrayList<>();
		HashSet<String> hs= new HashSet<>();
		for(int i=0; i<a+b; i++){
			String input=br.readLine();
			if(hs.contains(input)){
				answer.add(input);
			}
			else
				hs.add(input);
		}
		Collections.sort(answer);
		StringBuilder sb= new StringBuilder();
		sb.append(answer.size()+"\n");
		for(String temp : answer){
			sb.append(temp+"\n");
		}
		System.out.print(sb.toString());
	}

}