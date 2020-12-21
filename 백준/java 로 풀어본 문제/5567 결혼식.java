import java.io.IOException; 
import java.util.*;

public class Main { 
	public static void main(String[] args) throws IOException {
		Scanner s=new Scanner(System.in);
 
        int n = s.nextInt();
        int m = s.nextInt();
        int result=0;
        ArrayList<HashSet<Integer>> list=new ArrayList<HashSet<Integer>>();
        for(int i=0; i<=n; i++){
            list.add(new HashSet<Integer>());
        }
        for(int i=0; i<m; i++){
            int a,b;
            a=s.nextInt();
            b=s.nextInt();
            list.get(a).add(b);
            list.get(b).add(a);
        }
        Set<Integer> ffriend=new HashSet<Integer>();
        for(Integer temp : list.get(1)){
            ffriend.add(temp);
            for(Integer ttemp: list.get(temp)){
                ffriend.add(ttemp);
            }
        }
        ffriend.add(1);
        result=ffriend.size();
        System.out.print(result-1);
    }
}

