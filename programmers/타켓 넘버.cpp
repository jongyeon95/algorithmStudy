#include <string>
#include <vector>

using namespace std;
int answer = 0;
void dfs(vector<int> n,int result,int flag,int t){
    if(flag==n.size()){
        if(result==t)
            answer++;
        return;
    }
    dfs(n,result+n[flag],flag+1,t);
    dfs(n,result-n[flag],flag+1,t);
}

int solution(vector<int> numbers, int target) {
    dfs(numbers,0,0,target);
    return answer;
}