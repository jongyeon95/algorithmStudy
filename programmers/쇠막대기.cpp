#include <string>
#include <queue>
#include <vector>

using namespace std;

int solution(string arrangement) {
    int answer = 0;
    int flag=0;
    queue<char> q;
    for(int i=0;i<arrangement.size();i++){
     if(arrangement[i]=='('){
        q.push('(');
     }
        else{
            q.pop();
            if(arrangement[i-1]=='(')
                answer+= q.size();
            else
                answer+=1;
        }
            
    }
    return answer;
}