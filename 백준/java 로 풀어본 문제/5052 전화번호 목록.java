import java.io.*; 
import java.util.*;



public class Main {
   


    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        int testcase=Integer.parseInt(br.readLine());
        while(testcase-- > 0){
            HashSet<String> hs=new HashSet<>();
            int num=Integer.parseInt(br.readLine());
            String arr[]=new String[num];
            for(int i=0; i<num; i++){
                arr[i]=br.readLine();
            }
            Arrays.sort(arr);
            boolean result=true;
            for(int i=0; i<num; i++)
            {
                StringBuffer compareStr=new StringBuffer();
                boolean check=false;
                for (int j=0; j<arr[i].length(); j++) {
                    compareStr.append(arr[i].charAt(j));
                    if(hs.contains(compareStr.toString())){
                      check=true;
                      break;
                  }
                }
                if(!check){
                    hs.add(arr[i]);
                }
                else{
                    System.out.println("NO");
                    result=false;
                    break;
                }
            }
            if(result){
                System.out.println("YES");
            }
        }
       
    }      

}

