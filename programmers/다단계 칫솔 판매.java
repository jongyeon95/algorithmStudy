import java.util.*;
class Solution {
    public static HashMap<String,Seller> hm;
    
    public int[] solution(String[] enroll, String[] referral, String[] seller, int[] amount) {
        int[] answer = new int[enroll.length];
        hm=new HashMap<>();
        for(int i=0; i<enroll.length;i++){
            hm.put(enroll[i],new Seller());
            if(!referral[i].equals("-")){
                hm.get(enroll[i]).parent=referral[i];
            }
        }
        
        for(int i=0; i<seller.length; i++){
            String input=seller[i];
            hm.get(input).cost+=amount[i]*100;
            int cost=amount[i]*100;
            while(true){
                int recommandCost=cost/10;
                hm.get(input).cost-=recommandCost;
                if(hm.get(input).parent.equals(""))
                    break;
                hm.get(hm.get(input).parent).cost+=recommandCost;
                input=hm.get(input).parent;
                cost=recommandCost;
            }
        }
       
        for(int i=0; i<enroll.length; i++){
            answer[i]=hm.get(enroll[i]).cost;
        }
        
        
        return answer;
    }
}

class Seller{
    
    String parent;  
    int cost;
    public Seller(){
        this.parent="";
        this.cost=0;
    }
    
}