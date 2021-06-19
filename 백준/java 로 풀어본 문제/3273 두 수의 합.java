import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		long answer = 0L;
		int length = Integer.parseInt(br.readLine());
		int[] arr = new int[length];
		StringTokenizer stk = new StringTokenizer(br.readLine());
		for(int i=0; i<length; i++){
			arr[i]=Integer.parseInt(stk.nextToken());
		}
		int target=Integer.parseInt(br.readLine());
		int fIndex=0;
		int bIndex=length-1;
		Arrays.sort(arr);
		while(fIndex<bIndex){
			int num = arr[fIndex]+arr[bIndex];
			if(num>=target){
				if(num==target)
					answer++;
				bIndex--;
			}
			else{
				fIndex++;
			}
		}
		System.out.print(answer);


	}
}