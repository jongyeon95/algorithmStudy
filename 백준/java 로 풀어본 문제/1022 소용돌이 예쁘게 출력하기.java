import java.io.*; 
import java.util.*;



public class Main {
    
    public static void main(String[] args) throws IOException {
        BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st= new StringTokenizer(br.readLine());
        int r1,r2,c1,c2;
        r1=Integer.parseInt(st.nextToken());
        c1=Integer.parseInt(st.nextToken());
        r2=Integer.parseInt(st.nextToken());
        c2=Integer.parseInt(st.nextToken());
        solved(r1,c1,r2,c2);

    }
    public static void solved(int r1,int c1, int r2, int c2){
        int dx[]={0,-1,0,1};
        int dy[]={1,0,-1,0};
        int ty=0;
        int tx=0;
        int paper[][]=new int[r2-r1+1][c2-c1+1];
        int num=1;
        int cnt=0;
        int wcnt=0;
        int mcnt=1;
        int dir=0;
        while(true){
            if(wcnt>=(r2-r1+1)*(c2-c1+1))
                break;
            if(tx>=r1&&tx<=r2&&ty<=c2&&ty>=c1){
                paper[tx-r1][ty-c1]=num;
                wcnt++;
            }
            num++;
            cnt++;
            ty=ty+dy[dir];
            tx=tx+dx[dir];
            if(mcnt==cnt){
                cnt=0;
                if(dir==1||dir==3)
                    mcnt++;
                dir=(dir+1)%4;
            }
           
           
        }
        String s=Integer.toString(num);
        int length=s.length();
        for(int i=0; i<=r2-r1; i++){
            for(int j=0; j<=c2-c1; j++){
                int tempLength=Integer.toString(paper[i][j]).length();
                for(int k=0; k<length-tempLength; k++){
                    System.out.print(" ");
                }
                System.out.print(paper[i][j]+" ");
            }
            System.out.println();
        }

    }
}

