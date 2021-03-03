import java.util.*;
import java.io.*;

public class Main{


	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer stk = new StringTokenizer(br.readLine());
		String a = stk.nextToken();
		String b = stk.nextToken();
		int result[]=new int[81];
		int flag=0;
		int length=0;
		for(int i=a.length()-1; i>=0; i--){
			result[flag]+=a.charAt(i)-'0';
			flag++;
		}
		flag=0;
		for(int i=b.length()-1; i>=0; i--){
			result[flag]+=b.charAt(i)-'0';
			flag++;
		}
		for(int i=0; i<81; i++){
			if(result[i]>=2){
				result[i]%=2;
				result[i+1]++;
			}
		}
		for(int i=80; i>=0;i--){
			if(result[i]!=0){
				length=i;
				break;
			}
		}
		for(int i=length; i>=0; i--){
			System.out.print(result[i]);
		}

	}


}