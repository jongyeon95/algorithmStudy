import java.util.*;
class Solution {
    public long solution(long n) {
        long answer = 0;
        PriorityQueue<Long> pq=new PriorityQueue<Long>(Collections.reverseOrder());
        while(n>0){
            pq.offer(n%10);
            n/=10;
        }
        answer=pq.poll();
        while(!pq.isEmpty()){
            answer*=10;
            answer+=pq.poll();
        }
        return answer;
    }
}