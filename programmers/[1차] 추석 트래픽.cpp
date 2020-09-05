#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct timeInfo{
    int start;
    int end;
};

vector<timeInfo> timeLog;

bool cmp(timeInfo a, timeInfo b){
    if(a.end<b.end){
        return true;
    }
    else if(a.end==b.end){
        if(a.start<b.start)
            return true;
    }
    return false;
}

void changeToTimeInfo(string s){
    int originTime=0;
    int pcTime=0;
    originTime+=stoi(s.substr(11,2))*60*60*1000;
    originTime+=stoi(s.substr(14,2))*60*1000;
    originTime+=stoi(s.substr(17,2))*1000;
    originTime+=stoi(s.substr(20,3));
    if(s[25]=='.'){
        pcTime+=(s[24]-'0')*1000;
        pcTime+=stoi(s.substr(26));
    }
    else{
        pcTime+=(s[24]-'0')*1000;
    }
    timeLog.push_back({originTime-pcTime+1,originTime});

    
    return;
}

int solution(vector<string> lines) {
    int answer = 1;
    for(int i=0; i<lines.size(); i++){
        changeToTimeInfo(lines[i]);
    }
    sort(timeLog.begin(),timeLog.end(),cmp);
    for(int i=0; i<timeLog.size(); i++){
        int temp=0;
        for(int j=i; j<timeLog.size(); j++){
            if(timeLog[i].end+1000>timeLog[j].start){
                temp++;
            }
        }
        if(temp>answer)
            answer=temp;
    }
  
    
    return answer;
}