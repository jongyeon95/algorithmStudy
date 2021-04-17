
import java.util.*;
import java.io.*;

public class Main
{

	public static int n;
	public static int[] list;
	public static int[] lis;

	public static void main(String args[]) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer stk;
		n=Integer.parseInt(br.readLine());
		list=new int[n];
		lis=new int[n];
		stk=new StringTokenizer(br.readLine());
		for(int i=0; i<n; i++){
			list[i]=Integer.parseInt(stk.nextToken());
		}
		lis[0]=list[0];
		int lisIndex=1;
		
		for(int i=1; i<n; i++){
			if(lis[lisIndex-1]<list[i]){
				lis[lisIndex++]=list[i];
			}
			else{
				lis[binarySearch(list[i],lisIndex)]=list[i];
			}
		}
		System.out.print(lisIndex);
		
	}

	public static int binarySearch(int target, int lisSize){
		int left=0;
		int right=lisSize-1;
		int mid;
		while(left<right){
			mid=(left+right)/2;
			if(lis[mid]<target){
				left=mid+1;
			}
			else{
				right=mid;
			}
		}
		return right;

	}

}