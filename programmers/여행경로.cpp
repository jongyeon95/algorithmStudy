#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
bool visited[10000];
bool check=true;
vector<string> answer;
bool cmp(vector<string> a, vector<string> b){
    return a[1]<b[1];
}

void dfs(vector<string> v,vector<vector<string>> t){
    if(v.size()==t.size()+1){
        check=false;
        answer=v;
        return;
    }
    for(int i=0; i<t.size(); i++){
        if(v.back()==t[i][0]&&!visited[i]&&check){
            v.push_back(t[i][1]);
            visited[i]=true;
            dfs(v,t);
            v.pop_back();
            visited[i]=false;
        }
    }
    
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(),tickets.end(),cmp);
    memset(visited,false,sizeof(visited));
    for(int i=0; i<tickets.size(); i++){
       if(tickets[i][0]=="ICN"){
           vector<string> temp;
           temp.push_back("ICN");
           temp.push_back(tickets[i][1]);
           visited[i]=true;
           dfs(temp,tickets);
           visited[i]=false;
       }
      
        
    }   
    return answer;
}