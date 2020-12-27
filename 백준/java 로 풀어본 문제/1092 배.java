import java.io.*; 
import java.util.*;



public class Main {
    static int n;
    static int m;
    static ArrayList<Integer> crane=new ArrayList<>();
    static ArrayList<Integer> boxes=new ArrayList<>();
    static int maxNum;


    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        n=Integer.parseInt(br.readLine());
       
        StringTokenizer stk= new StringTokenizer(br.readLine());
        for(int i=0; i<n; i++){
            crane.add(Integer.parseInt(stk.nextToken()));
        }
        Collections.sort(crane,Collections.reverseOrder());
        m=Integer.parseInt(br.readLine());
       
        stk= new StringTokenizer(br.readLine());
        for(int i=0; i<m; i++){
            boxes.add(Integer.parseInt(stk.nextToken()));
        }
        Collections.sort(boxes,Collections.reverseOrder());
        if(boxes.get(0)>crane.get(0)){
            System.out.println(-1);
            return;
        }

        int cnt=0;
        int time=0;
       
        while(boxes.size()!=0){
            int index=0;
            int temp=0;
            while(index<n){
                if(temp==boxes.size())
                    break;
                if(crane.get(index)<boxes.get(temp)){
                    temp++;
                }
                else{
                    boxes.remove(temp);
                    index++;
                }
            }
            time++;
        }
        System.out.println(time);
       
    }      

}

