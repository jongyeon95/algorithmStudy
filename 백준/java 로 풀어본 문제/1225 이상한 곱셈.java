import java.util.*;
import java.io.*;

public class Main{
	
	public static void main(String arg[]){
		Scanner sc= new Scanner(System.in);
		String a=sc.next();
		String b=sc.next();
		long answer = 0L;
		for(int i=0; i<a.length(); i++){
			for(int j=0;j<b.length(); j++){
				answer+=(a.charAt(i)-'0')*(b.charAt(j)-'0');
			}
		}
		System.out.println(answer);

	}
}