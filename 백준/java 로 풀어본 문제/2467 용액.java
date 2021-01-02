import java.io.*; 
import java.util.*;


public class Main {
    
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        int n=Integer.parseInt(br.readLine());
        StringTokenizer stk = new StringTokenizer(br.readLine());
        int arr[]=new int[n];
        for (int i=0; i<n; i++) {
            arr[i]=Integer.parseInt(stk.nextToken());
        }
      

        int left=0;
        int right=n-1;
        int result=Integer.MAX_VALUE;
        int answer[]=new int[2];
        answer[0]=arr[left];
        answer[1]=arr[right];
        while(left<right){
            int l=arr[left];
            int r=arr[right];
            if(Math.abs(l+r)<result){
                result=Math.abs(l+r);
                answer[0]=l;
                answer[1]=r;
            }
            if(l+r<0)
                left++;
            else
                right--;
        }
        System.out.println(answer[0]+" "+answer[1]);
   
    }

}

