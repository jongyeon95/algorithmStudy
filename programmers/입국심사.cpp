#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long maxNum=0;
    for(int i=0; i<times.size(); i++){
        if(times[i]>maxNum)
            maxNum=(long long)times[i];
    }
    maxNum*=n;
    answer=maxNum;
    long long minNum=1;
    long long mid=(maxNum+minNum)/2;
    long long temp=0;
    while(minNum<=maxNum){
        mid=(maxNum+minNum)/2;
        temp=0;
        for(int i=0; i<times.size(); i++){
            temp=temp+mid/(long long)times[i];
        }
        if(temp<n){
            minNum=mid+1;
        } 
        else{
            if(answer>mid)
                answer=mid;
             maxNum=mid-1;
        }
        
    }
    return answer;
}