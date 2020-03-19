#include <string>
#include <vector>

using namespace std;
int max(int a, int b){
    if(a>=b)
        return a;
    return b;
}

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    for(int i=1;i<triangle.size();i++){
        for(int j=0; j<i+1;j++){
            if(j==0)
                triangle[i][0]+=triangle[i-1][0];
            else if(j==i)
                triangle[i][j]+=triangle[i-1][j-1];
            else{
                triangle[i][j]+=max(triangle[i-1][j-1],triangle[i-1][j]);
            }
        }
    }
    for(int i=0; i<triangle[triangle.size()-1].size(); i++){
        if(triangle[triangle.size()-1][i]>answer)
            answer=triangle[triangle.size()-1][i];
    }
    
    return answer;
}