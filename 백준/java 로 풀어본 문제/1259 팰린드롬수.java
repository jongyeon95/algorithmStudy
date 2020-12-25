import java.io.*; 
import java.util.*;



public class Main {
   
    public static void main(String[] args) throws IOException {
      BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
      while(true){
        String s=bf.readLine(); 
        if(s.equals("0")){
            break;
        }
        if(s.equals(new StringBuffer(s).reverse().toString()))
            System.out.println("yes");
        else
            System.out.println("no");
      }

    }
}

