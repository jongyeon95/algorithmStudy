#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

bool cmp(pair<int,double> p1, pair<int,double> p2){
    if(p1.second>p2.second){
        return true;
    }
    else if(p1.second==p2.second){
        if(p1.first<p2.first){
            return true;
        }
    }
    return false;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int,double>> temp;
    int check[stages.size()+2];
    memset(check,0,sizeof(check));
    
    for(int i=0; i<stages.size();i++){
        check[stages[i]]++;
    }
    for(int i=1; i<=N; i++){
        temp.push_back({i,0});
        for(int j=0; j<stages.size(); j++){
            if(stages[j]>=i){
                temp[i-1].second+=1;
            }
        }
        if(temp[i-1].second==0){
            temp[i-1].second=0;
            continue;
        }
        
        temp[i-1].second=check[i]/temp[i-1].second;
    }
    sort(temp.begin(),temp.end(),cmp);
    for(int i=0; i<temp.size(); i++){
        answer.push_back(temp[i].first);
    }
    
    return answer;
}