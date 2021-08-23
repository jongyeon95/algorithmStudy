#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
char intToChar(int score);
// scores_rows는 2차원 배열 scores의 행 길이, scores_cols는 2차원 배열 scores의 열 길이입니다.
char* solution(int** scores, size_t scores_rows, size_t scores_cols) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char* answer;
    answer=(char*)calloc(0,sizeof(char)*scores_rows);
    for(int i=0;i<scores_rows; i++){
        int high=-1;
        int row=101;
        int total=0;
        int cnt=scores_rows;
        bool h=true;
        bool r=true;
        for(int j=0; j<scores_cols; j++){
            total+=scores[j][i];
            if(scores[j][i]==high)
                h=false;
            if(scores[j][i]==row)
                r=false;
            if(scores[j][i]>high){
                h=true;
                high=scores[j][i];
            }
            if(scores[j][i]<row){
                r=true;
                row=scores[j][i];
            }
        }
        if(h&&high==scores[i][i]){
            total-=high;
            cnt--;
        }
        if(r&&row==scores[i][i]){
            total-=row;
            cnt--;
        }
 
        char a = intToChar(total/cnt);
        answer[i]=a;
    }
    
    return answer;
}

char intToChar(int score){
    if(score>=90)
        return 'A';
    if(score>=80)
        return 'B';
    if(score>=70)
        return 'C';
    if(score>=50)
        return 'D';
    return 'F';
}