#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int time=0;
    int job=0;
    int pFlag=0;
    while(pFlag<progresses.size()){
        if(progresses[pFlag]+(speeds[pFlag]*time)>=100){
            for(int i=pFlag; i<progresses.size();i++){
                if(progresses[pFlag]+(speeds[pFlag]*time)>=100){
                    job++;
                    pFlag++;
                }
                else{
                    answer.push_back(job);
                    job=0;
                    break;
                }
            }
        }
        time++;
    }
    answer.push_back(job);
    return answer;
}