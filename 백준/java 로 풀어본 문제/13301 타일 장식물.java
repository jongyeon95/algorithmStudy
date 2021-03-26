import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {

        StringBuilder sb = new StringBuilder();

       
        int i, N = System.in.read() - '0';
        if ((i = System.in.read()) > 13) N = 10 * N + i - '0';

        long[] square = new long[N+1];
        square[1]++;                 

        for (i = 2; i <= N; i++)   
            square[i] = square[i-2] + square[i-1];

        square[N] = (square[N] << 2) + (square[N-1] << 1);

        System.out.print(sb.append(square[N])); 

    }

}
