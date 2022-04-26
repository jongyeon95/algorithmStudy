import java.util.*;

public class Main {
    public static int n;
    public static int k;

    public static boolean[] checked;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n=sc.nextInt();
        k=sc.nextInt();
        checked=new boolean[n];
        String str = sc.next();
        int answer= 0;
        for(int i=0; i<n; i++){
            if(str.charAt(i)=='P'){
                int index = i-k;
                if(index<0) index = 0;
                for(int j=index; j<n&&j<=i+k; j++){
                    if(str.charAt(j)=='H'&& !checked[j]){
                        answer++;
                        checked[j]=true;
                        break;
                    }
                }
            }
        }
        System.out.println(answer);


    }

}
