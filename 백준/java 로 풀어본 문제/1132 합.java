import java.util.*;
import java.io.*;

public class Main
{
	public static boolean[] canZero;
	public static long[] alpha;
	public static Pair[] list;

	public static void main(String args[]) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		canZero=new boolean[10];
		alpha=new long[10];
		list=new Pair[10];
		long answer=0l;
		int n=Integer.parseInt(br.readLine());
		for(int i=0 ; i < n; i++){
			String input=br.readLine();
			canZero[input.charAt(0)-'A']=true;
			long num=1;
			for(int j=input.length()-1; j>=0; j--){
				alpha[input.charAt(j)-'A']+=num;
				num*=10;
			}
		}
		for(int i=0; i<10; i++){
			list[i]=new Pair(i,alpha[i]);
		}
		Arrays.sort(list);
		int zeroIndex=0;
		for(int i=9; i>=0; i--){
			if(!canZero[list[i].alpha]){
				zeroIndex=i;
				break;
			}
		}
		int cnt=9;
		for(int i=0; i<10; i++){
			if(i!=zeroIndex){
				answer+=list[i].cnt*cnt;
				cnt--;
			}
		}
		System.out.println(answer);
	}

}

class Pair implements Comparable<Pair>{
	int alpha;
	Long cnt;
	
	public Pair(int alpha, long cnt){
		this.alpha=alpha;
		this.cnt=cnt;
	}

	@Override
	public int compareTo(Pair o){
		return o.cnt.compareTo(this.cnt);
	}

}