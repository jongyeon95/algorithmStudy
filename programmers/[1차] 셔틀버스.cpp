#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;


string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    vector<int> newTimetable;
    
    for(int i=0; i<timetable.size();i++){
        newTimetable.push_back(
            {(timetable[i][0]-'0')*600+(timetable[i][1]-'0')*60+
                (timetable[i][3]-'0')*10+timetable[i][4]-'0'});
    }
    
    sort(newTimetable.begin(),newTimetable.end());
    vector<vector<int>> temp;
    temp.resize(n);
    
    int startTime=60*9;
    int cnt=0;
    int flag=0;
    
    while(cnt<n){
        
        for(int i=0; i<m; i++){
            if(newTimetable[flag]>startTime||flag>=newTimetable.size()){
                break;
            }
            temp[cnt].push_back(newTimetable[flag]);
            flag++;
        }
        cnt++;
        startTime+=t;
    }
    
    int hour;
    int minute;
    
    if(temp[temp.size()-1].size()<m){
        hour=(60*9+t*(n-1))/60;
        minute=(60*9+t*(n-1))%60;
    }
    else{
        int tempNum=temp[temp.size()-1][m-1]-1;
        hour=tempNum/60;
        minute=tempNum%60;
    }
    
    if(hour<10) answer+="0";
    answer+=to_string(hour)+":";
    
    if(minute<10) answer+="0";
    answer+=to_string(minute);
           
    
    return answer;
}