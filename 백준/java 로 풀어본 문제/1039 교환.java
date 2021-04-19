import java.util.*;
import java.io.*;

public class Main
{
	public static String input;
	public static int k;
	public static void main(String args[]) throws Exception
	{
		Scanner sc= new Scanner(System.in);
		input=sc.next();
		k=sc.nextInt();
		int answer=-1;
		Queue<String> q = new LinkedList<>();
		q.offer(input);
		for(int i=0; i<k; i++){
			if(q.isEmpty()){
				answer=-1;
				break;
			}
			HashSet<String> hs=new HashSet<String>();
			while(!q.isEmpty()){
				String temp = q.poll();
				for(int j=0; j<temp.length(); j++){
					for(int z=j+1; z<temp.length(); z++){
						char[] ch = temp.toCharArray();
						ch[j]=temp.charAt(z);
						ch[z]=temp.charAt(j);
						if(ch[0]!='0')
							hs.add(String.valueOf(ch));
					}
				}
			}
			for(String temp : hs){
				q.offer(temp);
			}
		}

		while(!q.isEmpty()){
			int temp = Integer.parseInt(q.poll());
			if(answer<temp){
				answer=temp;
			}
		}

		System.out.print(answer);

		
	}

}