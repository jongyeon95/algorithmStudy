import java.util.*;
import java.io.*;

public class Main{

	
	public static int n;
	public static int[] used;
	public static Queue<Integer> answer = new LinkedList<>();
	public static List<ArrayList<Integer>> list = new ArrayList<>();


	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer stk =new StringTokenizer(br.readLine());
		
		n = Integer.parseInt(stk.nextToken());
		int m = Integer.parseInt(stk.nextToken());
		used=new int[n+1];
		for(int i=0; i<=n; i++){
			list.add(new ArrayList<>());
		}

		for (int i=0; i<m; i++) {
			stk=new StringTokenizer(br.readLine());
			int size=Integer.parseInt(stk.nextToken());
			int pre=-1;
			for(int j=0; j<size; j++){
				int temp=Integer.parseInt(stk.nextToken());
				if(pre!=-1){
					list.get(pre).add(temp);
					used[temp]++;
				}
				pre=temp;
			}
		}

		Queue<Integer> q = new LinkedList<>();

		for(int i=1; i<=n; i++){
			if(used[i]==0){
				q.offer(i);
				used[i]--;
			}
		}

		while(!q.isEmpty()){
			int temp=q.poll();
			answer.offer(temp);
			for(int i=0; i<list.get(temp).size(); i++){
				used[list.get(temp).get(i)]--;
				if(used[list.get(temp).get(i)]==0){
					q.offer(list.get(temp).get(i));
					used[list.get(temp).get(i)]--;
				}
			}
		}
		if(answer.size()!=n){
			System.out.println(0);
		}
		else{
			while(!answer.isEmpty()){
				System.out.println(answer.poll());
			}
		}



	}
}