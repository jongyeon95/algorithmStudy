#include <string>
#include <vector>
#include <iostream>

using namespace std;
int dy[]={1,0,1};
int dx[]={0,1,1};

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    bool check=true;
    while(check){
        check=false;
        vector<pair<int,int>> eraseChar;
       
        // 4구역 같은곳 처리하기
        for(int i=0; i<m-1; i++){
            for(int j=0; j<n-1; j++){
                char temp=board[i][j];
                bool equalCheck=true;
                if(temp=='1')
                    continue;
                for(int k=0; k<3; k++){
                    if(board[i+dy[k]][j+dx[k]]!=temp){
                        equalCheck=false;
                        break;
                    }
                }
                if(equalCheck){
                    eraseChar.push_back({i,j});
                    check=true;
                }
            }
        }
        if(!check)
            break;
        
        // 없애진 곳 표시하기
        for(int i=0; i<eraseChar.size(); i++){
            board[eraseChar[i].first][eraseChar[i].second]='1';
            for(int j=0; j<3; j++){
                board[eraseChar[i].first+dy[j]][eraseChar[i].second+dx[j]]='1';
            }
        }
        
        // 빈공간 없애기 == 아래로 내리기
        for(int i=0; i<m; i++){
            for(int j=m-1; j>=0; j--){
                for(int k=m-1; k>=m-j; k--){
                    if(board[k][i]=='1'){
                        char temp=board[k-1][i];
                        board[k-1][i]=board[k][i];
                        board[k][i]=temp;
                    }
                }
            }
        }
    }
    
    //없어진 총합 찾기
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(board[i][j]=='1')
                answer++;
        }
    }
    return answer;
}