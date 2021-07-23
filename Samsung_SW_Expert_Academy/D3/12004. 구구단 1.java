
import java.util.Scanner;
import java.io.FileInputStream;


class Solution
{
	public static void main(String args[]) throws Exception
	{
        Scanner sc = new Scanner(System.in);
        boolean[] arr = new boolean[101];
		int T;
		T=sc.nextInt();
        for(int i=1; i<=9; i++)
            for(int j=1; j<=9; j++)
        		arr[i*j]=true;
        
		for(int test_case = 1; test_case <= T; test_case++)
		{
			int num=sc.nextInt();
            if(arr[num])	System.out.println("#"+test_case+" Yes");  
            else	System.out.println("#"+test_case+" No");
		}
	}
}