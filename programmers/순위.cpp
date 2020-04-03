#include <string>
#include <cstring>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    int arr[n+1][n+1];
    memset(arr,0,sizeof(arr));
    for(int i=0; i<results.size();i++){
        arr[results[i][0]][results[i][1]]=1;
        arr[results[i][1]][results[i][0]]=-1;
    }
    int cnt=2;
    while(cnt--){
        for(int i=1; i<n+1;i++){
            for(int j=1; j<n+1;j++){
                if(arr[i][j]==0)
                  continue;
                if(arr[i][j]==1){
                    for(int k=1; k<n+1; k++){
                        if(arr[j][k]==1)
                            arr[i][k]=1;
                    }
                }
                else if(arr[i][j]==-1)
                    for(int k=1; k<n+1; k++){
                        if(arr[j][k]==-1)
                            arr[i][k]=-1;
                    }
            }
        }
    }
    
    
    for(int i=1; i<n+1;i++){
       bool check=true;
        for(int j=1; j<n+1;j++){
            if(i==j)
                continue;
            if(arr[i][j]==0)
                check=false;
        }
        if(check)
            answer++;
    }
    return answer;
}