import java.util.*;
class Solution {
    public String[] solution(String[] files) {
        String[] answer = new String[files.length];
        ArrayList<File> list = new ArrayList<>();
        for(String input : files){
            list.add(new File(input));
        }
        Collections.sort(list);
        for(int i=0; i<answer.length; i++){
            answer[i]=list.get(i).origin;
        }
        return answer;
    }
}

class File implements Comparable<File>{
    String origin;
    String head;
    int number;
    
    public File(String input){
        this.origin=input;
        StringBuilder sb = new StringBuilder();
        int index=0;
        for(int i=0; i<input.length(); i++){
            char c = input.charAt(i);
            if(c>='0'&&c<='9'){
                index=i;
                this.head=sb.toString().toLowerCase();
                sb=new StringBuilder();
                break;
            }
            sb.append(c);
        }
        if(index==0){
            this.head=sb.toString().toLowerCase();
        }
        else{
            for(int i=index; i<input.length(); i++){
                char c = input.charAt(i);
                if(c>='0'&&c<='9'){
                   sb.append(c);
                }
                else{
                    break;
                }
            }
            this.number=Integer.parseInt(sb.toString());
        }
    }
    @Override
    public int compareTo(File o){
        if(this.head.equals(o.head)){
            return this.number-o.number;
        }
        return this.head.compareTo(o.head);
    }
    
    
}