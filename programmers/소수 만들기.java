class Solution {
    public static boolean[] isPrime;
    public int solution(int[] nums) {
        int answer = 0;
        makePrime();
        for(int i=0; i<nums.length-2; i++){
            for(int j=i+1; j<nums.length-1; j++){
                for(int k=j+1; k<nums.length; k++){
                    int temp=nums[i]+nums[j]+nums[k];
                    if(!isPrime[temp])
                        answer++;
                }
            }
        }

        return answer;
    }
    
    public static void makePrime(){
        isPrime=new boolean[50001];
        for(int i=2; i*i<50001; i++){
            if(isPrime[i]) continue;
            for(int j=i+i; j<50001; j+=i){
                isPrime[j]=true;
            }
        }
    }
}