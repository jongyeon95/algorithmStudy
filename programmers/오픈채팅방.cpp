#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

map<string,string> m;

vector<string> solution(vector<string> record) {
    vector<vector<string>> temp;
    temp.resize(record.size());
    for(int i=0; i<record.size(); i++){
         string s="";
        for(int j=0; j<record[i].size();j++){
            if(record[i][j]==' '){
                temp[i].push_back(s);
                s.clear();
            }
            else{
                s+=record[i][j];
            }
            if(j==record[i].size()-1){
                temp[i].push_back(s);
            }
        }
        if(temp[i][0]=="Enter"){
            m.erase(temp[i][1]);
            m.insert({temp[i][1],temp[i][2]});
        }
        else if(temp[i][0]=="Change"){ 
            m.erase(temp[i][1]);
           m.insert({temp[i][1],temp[i][2]});
        }
    }
    vector<string> answer;
    
    for(int i=0; i<temp.size(); i++){
        string result="";
        if(temp[i][0]=="Change"){
            continue;
        }
       
        result+=m.find(temp[i][1])->second;
        
        if(temp[i][0]=="Enter"){
            result+="님이 들어왔습니다.";
        }
        else{
            result+="님이 나갔습니다.";
        }
        answer.push_back(result);
    }
    
    return answer;
}