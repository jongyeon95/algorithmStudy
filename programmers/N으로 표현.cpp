#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int answer =9;

void dfs(int n, int number, int idx, int sum){
    if(idx>8) return;
    
    if(sum == number) {
        answer = min(answer, idx);
    }
    
    int tmp = 0;
    for(int i=0; i<8; i++){
        tmp = tmp*10 + n;
        dfs(n, number, idx+i+1, sum+tmp);
        dfs(n, number, idx+i+1, sum-tmp);
        dfs(n, number, idx+i+1, sum*tmp);
        dfs(n, number, idx+i+1, sum/tmp);
    }
}

int solution(int N, int number) {
    dfs(N, number, 0, 0);
    if(answer >8) return -1;
    else return answer;
}