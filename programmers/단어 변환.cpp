#include <string>
#include <cstring>
#include <vector>

using namespace std;

bool visited[50];
int answer;
string t;
void dfs(vector<string> w, string s, int cnt){
    int checkNum=0;
    if(s==t){
        if(cnt<answer)
            answer=cnt;
        return;
    }
    for(int i=0; i<w.size(); i++){
        checkNum=0;
        if(!visited[i]){
            for(int j=0; j<s.size(); j++){
                if(s[j]!=w[i][j]){
                    checkNum++;
                }
            }
            if(checkNum==1){
                visited[i]=true;
                dfs(w,w[i],cnt+1);
                visited[i]=false;
            }
        }
    }
    
}
int solution(string begin, string target, vector<string> words) {
    answer =51;
    t=target;
    memset(visited,false,sizeof(visited));
    dfs(words,begin,0);
    if(answer==51)
        answer=0;
    
    return answer;
}