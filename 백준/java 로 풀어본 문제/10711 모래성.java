import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int H = Integer.parseInt(input[0]);
        int W = Integer.parseInt(input[1]);
        char[][] map = new char[H][W];
        boolean[][] none = new boolean[H][W];
        Queue<Pair> noSand = new LinkedList<>();
        Queue<Pair> remove = new LinkedList<>();
        int[] dx = {-1, -1, -1, 0, 1, 1, 0, 1};
        int[] dy = {-1, 0, 1, 1, 1, -1, -1, 0};

        for(int i=0; i<H; i++) {
            String str = br.readLine();
            for(int j=0; j<W; j++) {
                char x = str.charAt(j);
                map[i][j] = x;
                
                if(x=='.') {
                    noSand.add(new Pair(i, j));
                    none[i][j] = true;
                }
            }
        }

        int t = 0;
        int[][] count = new int[H][W];

        while(noSand.size()!=0) {
            int s = noSand.size();

            for(int i=0; i<s; i++) {
                Pair temp = noSand.poll();

                for(int j=0; j<8; j++) {
                    int nx = temp.x+dx[j];
                    int ny = temp.y+dy[j];

                    if(nx<0 || nx>=H || ny<0 || ny>=W || none[nx][ny]) continue;

                    if(map[nx][ny]!='.') {
                        count[nx][ny]++;

                        if(count[nx][ny]>=map[nx][ny]-'0') {
                            none[nx][ny] = true;
                            remove.add(new Pair(nx, ny));
                        }
                    }
                }
            }
            
            while(!remove.isEmpty()) {
                Pair rm = remove.poll();
                noSand.add(new Pair(rm.x, rm.y));
            }

            t++;
        }

        System.out.println(t-1);
    }

    public static class Pair {
        int x;
        int y;

        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}