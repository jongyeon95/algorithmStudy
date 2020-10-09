#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int cnt=0;
    long long number=num;
    int answer = 0;
    while(number!=1&&cnt++<500){
        if(number%2==0){
            number/=2;
        }
        else{
            number=number*3+1;
        }
        answer++;
    }
    if(answer==500)
        answer=-1;
    return answer;
}