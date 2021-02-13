import java.util.*;
import java.io.*;

public class Main{

	public static void main(String arg[]) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n=Integer.parseInt(br.readLine());
		String str=br.readLine();
		Stack<Double> stk=new Stack<>();
		int arr[]= new int[26];
		for(int i=0; i<n; i++){
			arr[i]=Integer.parseInt(br.readLine());
		}
		for(int i=0; i<str.length(); i++){
			if(str.charAt(i)<='Z'&&str.charAt(i)>='A'){
				stk.push(Double.valueOf(arr[str.charAt(i)-'A']));
			}
			else{
				char c= str.charAt(i);
				Double b=stk.pop();
				Double a=stk.pop();
				Double result=0.0;

				switch(c){
					case '+' : result=a+b;
					break;
					case '-' : result=a-b;
					break;
					case '*' : result=a*b;
					break;
					case '/' : result=a/b;
					break;
				}

				stk.push(result);
			}
		}
		System.out.println(String.format("%.2f",stk.pop()));
	}

}