#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(),people.end());
    int frontFlag=0;
    int endFlag=people.size()-1;
    while(frontFlag<endFlag){
        if((people[frontFlag]+people[endFlag])<=limit){
            answer++;
            people[frontFlag]=0;
            people[endFlag]=0;
            frontFlag++;
            endFlag--;
        }
        else
            endFlag--;
    }
    for(int i=0; i<people.size(); i++){
        if(people[i]!=0)
            answer++;
    }
    return answer;
}