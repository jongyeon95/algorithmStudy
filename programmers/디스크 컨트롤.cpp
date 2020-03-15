#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool cmp(vector<int> a, vector<int> b){
    if(a[1]==b[1])
        return a[0]<b[0];
    return a[1]<b[1];
}

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int start=0;
    int time=0;
    sort(jobs.begin(),jobs.end(),cmp);
    int size=jobs.size();
    while(jobs.size()>0){
        for(int i=0; i<jobs.size();i++){
            if(jobs[i][0]<=start){
                start+=jobs[i][1];
                time+=start-jobs[i][0];
                jobs.erase(jobs.begin()+i);
                break;
            }
            if(i==jobs.size()-1)
                start+=1;
        }
    }
    
    answer=time;
    
    return answer/size;
}