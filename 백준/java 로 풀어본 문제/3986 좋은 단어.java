import java.util.*;
import java.io.*;

public class Main{

	public static void main(String arg[]) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n=Integer.parseInt(br.readLine());
		int answer=0;
		while(n-- > 0){
			String input=br.readLine();
			Stack<Character> s=new Stack<>();
			for(int i=0; i<input.length(); i++){
				if(s.empty()){
					s.push(input.charAt(i));
				}
				else{
					if(s.peek()==input.charAt(i)){
						s.pop();
					}
					else{
						s.push(input.charAt(i));
					}
				}
			}
			if(s.empty())
				answer++;
		}
		System.out.println(answer);
	}

}