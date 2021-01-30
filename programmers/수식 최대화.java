import java.util.*;
class Solution {
    public long solution(String expression) {
        long answer = 0;
        List<String> list=new ArrayList<>();
        int start=0;
        
        for(int i=0; i<expression.length(); i++){
            char temp = expression.charAt(i);
            if(temp=='*'){
                list.add(expression.substring(start,i));
                list.add("*");
                start=i+1;
            }
            if(temp=='-'){
                list.add(expression.substring(start,i));
                list.add("-");
                start=i+1;
            }
            if(temp=='+'){
                list.add(expression.substring(start,i));
                list.add("+");
                start=i+1;
            }
        }
        list.add(expression.substring(start));
        
        
        return solve(list);
    }
    
    public long solve(List<String> list){
        int arr[][]={{0,1,2},{0,2,1},{1,0,2},{1,2,0},{2,0,1},{2,1,0}};
        String c[]={"*","+","-"};
        long result=0;
        for(int i=0; i<6; i++){
            List<String> temp = new ArrayList<>();
            temp.addAll(list);
            for(int j=0; j<3; j++){
                for(int k=0; k<temp.size();k++){
                    if(temp.get(k).equals(c[arr[i][j]])){
                        if(c[arr[i][j]].equals("*")){
                            temp.set(k-1,Long.toString((Long.parseLong(temp.get(k-1))*Long.parseLong(temp.get(k+1)))));
                        }
                        else if(c[arr[i][j]].equals("+"))
                            temp.set(k-1,Long.toString((Long.parseLong(temp.get(k-1))+Long.parseLong(temp.get(k+1)))));
                        else 
                            temp.set(k-1,Long.toString((Long.parseLong(temp.get(k-1))-Long.parseLong(temp.get(k+1)))));
                        temp.remove(k);
                        temp.remove(k); 
                        k--;
                    }
                }
            }
           
            if(Math.abs(Long.parseLong(temp.get(0)))>result){
                result=Math.abs(Long.parseLong(temp.get(0)));
            }
        }
        return result;
    }
}