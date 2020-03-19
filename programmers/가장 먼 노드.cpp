#include <string>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    bool node[n+1];
    vector<vector<int>> v;
    int maxLength=0;
    memset(node,false,sizeof(node));
  
    for(int i=0; i<=n; i++){
        vector<int> temp;
        temp.push_back(i);
        v.push_back(temp);
    }
    for(int i=0; i<edge.size(); i++){
       v[edge[i][0]].push_back(edge[i][1]);
       v[edge[i][1]].push_back(edge[i][0]);
    }
    
    queue<pair<int,int>> q;
    q.push({1,0});
    node[1]=true;
    while(!q.empty()){
        pair<int,int> temp=q.front();
        q.pop();
        if(temp.second>maxLength){
            maxLength=temp.second;
            answer=1;
        }
        else if(temp.second==maxLength){
            answer++;
        }
        for(int i=0; i<v[temp.first].size();i++){
            if(!node[v[temp.first][i]]){
                node[v[temp.first][i]]=true;
                q.push({v[temp.first][i],temp.second+1});
            }
        }
    }
    
    
    
    
    
    return answer;
}