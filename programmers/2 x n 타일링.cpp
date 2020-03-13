#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    long long answer = 0;
    if(n==1)
        return 1;
    if(n==2)
        return 2;
    long long tempA=1;
    long long tempB=2;
    for(int i=3; i<=n;i++){
        answer=(tempA+tempB)%1000000007;
        tempA=tempB;
        tempB=answer;
    }
    
    return answer;
}