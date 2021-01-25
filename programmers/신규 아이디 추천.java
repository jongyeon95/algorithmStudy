class Solution {
    public String solution(String new_id) {
        String answer = "";
       
        StringBuilder sb= new StringBuilder();
        
        sb.append(new_id.replaceAll("[^\\w-_.]","").toLowerCase().replaceAll("[.]{2,}","."));
       
        if(sb.length()>0){
            if(sb.charAt(0)=='.'){
                sb.deleteCharAt(0);    
            }
            if(sb.length()>0&&sb.charAt(sb.length()-1)=='.'){
                sb.deleteCharAt(sb.length()-1);
            }
        }
        if(sb.length()==0){
            sb.append("a");
        }
       
        if(sb.length()>15){
            sb.delete(15,sb.length());
            if(sb.charAt(14)=='.'){
                sb.deleteCharAt(14);
            }
        }
       
        if(sb.length()<3){
            while(sb.length()<3){
                sb.append(sb.charAt(sb.length()-1));
            }
        }
        
        
        return sb.toString();
    }
}