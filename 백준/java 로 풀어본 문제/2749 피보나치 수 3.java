import java.util.*;
import java.io.*;

public class Main{

	public static void main(String[] args) throws IOException{
		Scanner sc = new Scanner(System.in);
		long n = sc.nextLong();
		long list[]=new long[1500001];
		list[0]=0L;
		list[1]=1L;
		for(int i=2; i<=1500000; i++){
			list[i]=list[i-1]+list[i-2];
			list[i]%=1000000;
		}
		System.out.print(list[(int)(n%1500000)]);
	}
}