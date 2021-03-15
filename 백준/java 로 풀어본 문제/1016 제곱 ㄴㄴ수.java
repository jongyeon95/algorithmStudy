import java.util.*;
import java.io.*;

public class Main{

	public static void main(String[] args) throws IOException{
		Scanner sc= new Scanner(System.in);
		long min=sc.nextLong();
		long max=sc.nextLong();
		boolean[] arr = new boolean[(int)(max-min+1)];

        for(long i = 2; i*i <= max; i++) {
            long powNum = i*i;
            long startNum = min + (powNum -(min%powNum))%powNum;

            for(long j = startNum; j <= max; j += powNum) {
                arr[(int)(j - min)] = true;
            }
        }

        int cnt = 0;
        for(int i = 0; i < arr.length; i++) {
            if(!arr[i])
                cnt++;
        }

        System.out.println(cnt);
		}

}