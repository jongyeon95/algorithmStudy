import java.io.IOException;
import java.util.Scanner;
public class Main{
	public static void main(String[] args) throws Exception{
		Scanner s= new Scanner(System.in);
		int num=s.nextInt();
		Long arr[]=new Long[num+1];
		if(num==1||num==0){
			System.out.print(num);
			return;
		}
		arr[0]=0L;
		arr[1]=1L;
		for (int i=2; i<=num; i++){
			arr[i]=arr[i-2]+arr[i-1];
		}
		System.out.print(arr[num]);


	}
}