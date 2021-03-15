import java.util.*;
import java.io.*;

public class Main{
	public static void main(String[] args) throws IOException {
		BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw= new BufferedWriter(new OutputStreamWriter(System.out));

		while(true){
			String input=br.readLine();
			if(input.equals(".")){
				bw.flush();
				bw.close();
				return;
			}
			int size=input.length();
			List<Integer> list = new ArrayList<>();
			for(int i=1; i<=size; i++){
				if(size%i==0){
					list.add(i);
				}
			}
			int flag=0;
			while(true)
			{	
				boolean check=true;
				int subSize=list.get(flag);
				String firstWord=input.substring(0,subSize);
				for(int i=subSize; i+subSize<=size; i+=subSize){
					if(!firstWord.equals(input.substring(i,i+subSize))){
						check=false;
						break;
					}
				}
				if(check){
					bw.write(size/subSize+"\n");
					break;
				}
				flag++;
			}

		}
		
	}
}