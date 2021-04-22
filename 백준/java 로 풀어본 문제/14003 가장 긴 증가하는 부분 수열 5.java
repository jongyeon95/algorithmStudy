import java.util.*;
import java.io.*;

public class Main
{
	public static int n;
	public static int[] list;
	public static int[] index;
	public static int[] arr;
	public static int answerSize=1;
	public static void main(String args[]) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer stk;
		n=Integer.parseInt(br.readLine());
		stk=new StringTokenizer(br.readLine());
		list=new int[n];
		index=new int[n];
		arr=new int[n];
		arr[0]=Integer.parseInt(stk.nextToken());
		list[0]=arr[0];
		index[0]=0;

		for(int i=1; i<n; i++){
			int temp = Integer.parseInt(stk.nextToken());
			arr[i]=temp;
			if(list[answerSize-1]<temp){
				index[i]=answerSize;
				list[answerSize++]=temp;
			}
			else{
				int idx = binarySearch(temp);
				index[i]=idx;
				list[idx]=temp;
			}

		}
		bw.write(answerSize+"\n");
		int[] answer=new int[answerSize];
		int cnt=0;
		answerSize--;
		
		for(int i=n-1;i>=0; i--){
			if(index[i]==answerSize){
				answer[answerSize]=arr[i];
				answerSize--;
			}
			if(answerSize<0)
				break;
		}
		for(int i=0; i<answer.length; i++){
			bw.write(answer[i]+" ");
		}
		bw.flush();
		bw.close();


	
	}
	public static int binarySearch(int num){
		int left=0;
		int right=answerSize-1;
		int mid;
		while(left<right){
			mid=(left+right)/2;
			if(list[mid]<num){
				left=mid+1;
			}
			else{
				right=mid;
			}
		}
		return right;
	}

}

