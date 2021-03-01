import java.io.*;
import java.util.*;
 
public class Main {

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        String input=sc.next();
        char[] c = new char[26];
        c['E'-'A']='I';
        c['I'-'A']='E';
        c['S'-'A']='N';
        c['N'-'A']='S';
        c['T'-'A']='F';
        c['F'-'A']='T';
        c['J'-'A']='P';
        c['P'-'A']='J';
        StringBuilder sb=new StringBuilder();
        for(int i=0; i<4; i++){
            sb.append(c[input.charAt(i)-'A']);
        }
        System.out.println(sb.toString());
 
    }
}
