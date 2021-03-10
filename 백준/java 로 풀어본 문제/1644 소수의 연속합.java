import java.util.*;
import java.io.*;

public class Main{

	public static boolean num[]= new boolean[4000001];
	public static List<Integer> list = new ArrayList<Integer>();
	public static HashMap<Integer,Integer> hm = new HashMap<>();

	public static void main(String[] args) throws IOException{
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int answer=0;

		for(int i=2; i<=4000000; i++){
			if(num[i])
				continue;
			else{
				list.add(i);
			}
			for(int j=i*2; j<=4000000; j+=i){
				num[j]=true;
			}
		}
		

		
		for(int i=0; i<list.size(); i++){
			int temp=0;
			for(int j=i; j<list.size(); j++){
				temp+=list.get(j);
				if(temp>n)
					break;
				if(hm.get(temp)==null){
					hm.put(temp,1);
				}
				else
					hm.put(temp,hm.get(temp)+1);
			}
		}

		if(hm.get(n)!=null)
			answer=hm.get(n);
		System.out.print(answer);
		
	}
}