import java.util.*;
import java.io.*;

class Pair{
	String str;
	Integer cnt;
	public Pair(String s, Integer c){
		this.str=s;
		this.cnt=c;
	}
}

public class Main{
	static int dy[]={1,-1,0,0};
	static int dx[]={0,0,1,-1};
	public static void main(String arg[]) throws IOException{
		Scanner sc= new Scanner(System.in);
		StringBuilder input= new StringBuilder();
		HashSet<String> visited= new HashSet<String>();
		
		int answer=987654321;
		for(int i=0; i<9; i++)
			input.append(sc.next());
		Queue<Pair> q= new LinkedList<>();
		visited.add(input.toString());

		q.offer(new Pair(input.toString(),0));
		while(!q.isEmpty()){
			Pair temp=q.poll();
			if(temp.str.equals("123456780")){
				if(answer>temp.cnt){
					answer=temp.cnt;
					continue;
				}
			}
			else{
				int zero=temp.str.indexOf("0");
				int row=zero/3;
				int col=zero%3;
				for(int i=0; i<4; i++){
					int nx=row+dx[i];
					int ny=col+dy[i];
					int to=nx*3+ny;
					if(nx < 0 || nx >= 3 || ny < 0 || ny >= 3)
						continue;
					String newStr=swap(temp.str,zero,to);
					if(visited.contains(newStr))
						continue;
					q.offer(new Pair(newStr,temp.cnt+1));
					visited.add(newStr);
				}
			}

		}
		if(answer==987654321)
			answer=-1;
		System.out.println(answer);

	}

	public static String swap(String str,int zero, int to){
		StringBuilder sb= new StringBuilder(str);
		char temp=sb.charAt(to);
		sb.setCharAt(zero,temp);
		sb.setCharAt(to,'0');
		return sb.toString();

	}
}