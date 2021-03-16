import java.util.*;
import java.io.*;

public class Main{
	public static String[] map;
	public static void main(String[] args) throws IOException{
		int answer=0;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer stk= new StringTokenizer(br.readLine());
		int n=Integer.parseInt(stk.nextToken());
		int m=Integer.parseInt(stk.nextToken());
		map=new String[n];
		for(int i=0; i<n; i++){
			map[i]=br.readLine();
		}
		int maxSize= n < m ? n : m;

		for(int k=maxSize; k>=1; k--){
			for(int i=0; i<=n-k; i++){
				for(int j=0; j<=m-k; j++){
					if(isSquare(i,j,k)){
						answer=k*k;
						System.out.println(answer);
						return;
					}
				}
			}
		}

		System.out.println(answer);
	}

	public static boolean isSquare(int y, int x, int size){
		if(map[y].charAt(x)==map[y].charAt(x+size-1)&&map[y].charAt(x)==map[y+size-1].charAt(x)&&map[y].charAt(x)==map[y+size-1].charAt(x+size-1)){
			return true;
		}
		return false;
	}
}