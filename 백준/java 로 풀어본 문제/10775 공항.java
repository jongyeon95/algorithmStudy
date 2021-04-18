import java.util.*;
import java.io.*;

public class Main
{
	public static int[] gate;
	public static int p;

	public static void main(String args[]) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int gateSize=Integer.parseInt(br.readLine());
		int ans=0;
		gate=new int[gateSize+1];
		for(int i=0; i<=gateSize; i++){
			gate[i]=i;
		}
		p=Integer.parseInt(br.readLine());
		for(int i=0; i<p; i++){
			int plane=Integer.parseInt(br.readLine());
			int temp=find(plane);
			if(temp!=0){
				union(temp,temp-1);
				ans++;
			}
			else{
				break;
			}
		}
		System.out.println(ans);
		
	}

	public static int find(int index){
		if(gate[index]==index)
			return index;
		return gate[index]=find(gate[index]);
	}
	public static void union(int a, int b){
		a=find(a);
		b=find(b);
		gate[a]=b;
	}

}