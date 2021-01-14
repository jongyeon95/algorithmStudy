class Solution
{
    public int solution(String s)
    {
        int answer = 1;
        for(int i=0; i<s.length(); i++){
            for(int j=s.length()-1; j>i; j--){
                if(!(j-i+1>answer))
                    break;
                if((s.charAt(i)==s.charAt(j))){
                    boolean check=true;
                    for(int k=i; k<=(j+i)/2; k++){
                        if(s.charAt(k)!=s.charAt(j+i-k)){
                            check=false;
                            break;
                        }
                    }
                    if(check){
                        answer=j-i+1;
                    }
                }
            }
        }
       

        return answer;
    }
}