#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    answer.push_back(0);
    for(int i=1; i<heights.size();i++){
        bool ZeroCheck=true;
        for(int j=i; j>=0; j--){
            if(heights[i]<heights[j]){
                answer.push_back(j+1);
                ZeroCheck=false;
                break;
            }
        }
        if(ZeroCheck)
             answer.push_back(0);
            
    }
    return answer;
}