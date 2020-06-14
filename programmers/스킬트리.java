import java.util.*;
class Solution {

    public int solution(String skill, String[] skill_trees) {
        int answer = 0;
        Boolean[] alphabet= new Boolean[26];
        for(int i=0; i<skill_trees.length; i++){
             Arrays.fill(alphabet,false);
            for(int j=0; j<skill.length(); j++){
               alphabet[skill.charAt(j)-'A']=true;
            }
            Boolean check=true;
            int flag=0;
            for(int j=0; j<skill_trees[i].length(); j++){
                if(alphabet[skill_trees[i].charAt(j)-'A']){
                    if(skill_trees[i].charAt(j)==skill.charAt(flag)){
                        flag++;
                        alphabet[skill_trees[i].charAt(j)-'A']=false;
                    }
                    else{
                        check=false;
                        break;
                    }
                }
            }
            if(check){
                 answer++;
            }
               
        }
        return answer;
    }
}