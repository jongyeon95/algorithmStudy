import java.util.*;
import java.io.*;

public class Main {
 
    public static void main(String[] args) {
 
        Scanner sc = new Scanner(System.in);
 
        int lotation = sc.nextInt();
        boolean[] arr = new boolean[4];
        boolean test = false;
 
        arr[1] = true;
        arr[2] = false;
        arr[3] = false;
 
      
        for (int i = 0; i < lotation; i++) {
            int num1 = sc.nextInt();
            int num2 = sc.nextInt();
 
            test = arr[num1];
            arr[num1] = arr[num2];
            arr[num2] = test;
 
        } 
 
      
        for (int i = 1; i < 4; i++) {
            if (arr[i] == true)
                System.out.println(i);
        } 
    }
 
}