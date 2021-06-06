import java.util.*;
import java.io.*;

public class Main{
	public static HashMap<String,Integer> hm = new HashMap<>();
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n= Integer.parseInt(br.readLine());
		while(n -- > 0){
			String input = br.readLine();
			if(hm.get(input)==null){
				hm.put(input,1);
			}
			else
				hm.put(input,hm.get(input)+1);
		}
		ArrayList<Pair> list = new ArrayList<Pair>();
		for(Map.Entry<String,Integer> entry : hm.entrySet()){
			list.add(new Pair(entry.getKey(),entry.getValue()));
		}
		Collections.sort(list);
		System.out.println(list.get(0).name);
	}

	
}

class Pair implements Comparable<Pair>{
	String name;
	int cnt;
	public Pair(String name, int cnt){
		this.name=name;
		this.cnt=cnt;
	}

	@Override
	public int compareTo(Pair o){
		if(this.cnt==o.cnt)
			return this.name.compareTo(o.name);
		return o.cnt-this.cnt;
	}
}
