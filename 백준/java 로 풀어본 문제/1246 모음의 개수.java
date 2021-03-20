import java.util.*;
import java.io.*;

public class Main{
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		while(true){
			String inputLine=br.readLine();
			if(inputLine.equals("#"))
				return;
			int size=inputLine.length()-inputLine.replaceAll("[aeiouIOUEA]","").length();
			System.out.println(size);
		}
	}
}