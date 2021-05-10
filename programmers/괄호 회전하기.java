import java.util.*;
class Solution {
    public int solution(String s) {
        int answer = 0;
        String input=s+s;
        int length=s.length();
        for(int i=0; i<length;i++){
            if(check(i,i+length,input)){
                answer++;
            }
        }
        return answer;
    }
    
    public static boolean check(int start, int end, String input){
        Stack<Character> s = new Stack<Character>();
        for(int i=start;i<end;i++){
            char c = input.charAt(i);
            if(s.empty()){
                if(c=='}'||c==')'||c==']')
                    return false;
                else
                    s.push(c);
            }
            else{
                if(c=='}'){
                    if(s.peek()=='{') s.pop();
                    else return false;
                }
                else if(c==')'){
                    if(s.peek()=='(') s.pop();
                    else return false;
                }
                else if(c==']'){
                    if(s.peek()=='[') s.pop();
                    else return false;
                }
                else
                    s.push(c);
            }
        }
        if(!s.empty())
            return false;
        return true;
    }
}