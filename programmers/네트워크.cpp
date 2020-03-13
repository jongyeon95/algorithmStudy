#include <string>
#include <cstring>
#include <vector>
using namespace std;
bool visited[200];

void dfs(int s, vector<vector<int>> &c , int n){
    
    for(int i=0; i<n; i++){
        if(c[s][i]==1&& !visited[i]){
            visited[i]=true;
            dfs(i,c,n);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    memset(visited,false,sizeof(visited));
    for(int i=0; i<n; i++){
        if(!visited[i]){
            visited[i]=true;
            answer++;
            dfs(i,computers,n);
            
        }
    }
    return answer;
}