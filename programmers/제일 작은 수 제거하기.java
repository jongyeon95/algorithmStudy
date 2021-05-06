class Solution {
    public int[] solution(int[] arr) {
        int[] answer = new int[arr.length];
        if(arr.length==1){
            answer[0]=-1;
            return answer;
        }
        int index=0;
        for(int i=0; i<arr.length; i++){
            if(arr[i]<arr[index]){
                index=i;
            }
        }
        answer=new int[arr.length-1];
        int iindex=0;
        for(int i=0; i<arr.length; i++){
            if(index==i){
                continue;
            }
            answer[iindex]=arr[i];
            iindex++;
        }
            
        return answer;
    }
}