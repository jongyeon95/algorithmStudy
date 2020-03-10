#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    answer.push_back(0);
    for(int i=1;i<n;i++){
        int size=answer.size();
         answer.push_back(0);
        for(int j=size-1; j>=0; j--){
            if(answer[j]==0)
                answer.push_back(1);
            else
                answer.push_back(0);
        }
    }
    return answer;
}