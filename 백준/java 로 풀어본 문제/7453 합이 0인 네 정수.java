import java.util.*;
import java.io.*;

public class Main
{
	public static int n;
	public static int[][] arr;
	
	public static void main(String args[]) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer stk;
		n=Integer.parseInt(br.readLine());
		arr=new int[n][4];
		for(int i=0; i<n; i++){
			stk=new StringTokenizer(br.readLine());
			for(int j=0; j<4; j++){
				arr[i][j]=Integer.parseInt(stk.nextToken());
			}
		}
		long[] ab=new long[n*n];
		long[] cd=new long[n*n];
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				ab[i*n+j]=arr[i][0]+arr[j][1];
				cd[i*n+j]=arr[i][2]+arr[j][3];
			} 
		}
		Arrays.sort(ab);
		Arrays.sort(cd);
		int aIndex=0;
		int cIndex=n*n-1;
		long answer=0;
		while(aIndex<n*n&&cIndex>=0){
			long temp = ab[aIndex]+cd[cIndex];
			if(temp==0){
				long acnt=0;
				long bcnt=0;
				long asum=ab[aIndex];
				long csum=cd[cIndex];
				while(aIndex<n*n&&ab[aIndex]+csum==0){
					aIndex++;
					acnt++;
				}
				while(cIndex>=0&&asum+cd[cIndex]==0){
					cIndex--;
					bcnt++;
				}
				answer+=acnt*bcnt;
			}
			else if(temp > 0){
				cIndex--;
			}
			else{
				aIndex++;
			}

		}
		System.out.print(answer);
		
	}
	
}

