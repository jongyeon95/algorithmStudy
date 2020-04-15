#include<iostream>
#include<string>
using namespace std;   
string s; 
int row, col, n, cnt; 
char a[101][101]; 
int main(){
    cin >> n; 
    for(int i = 0; i < n; i++){
        cin >> s; 
        cnt = 0;  
        for(int j = 0; j < s.size(); j++){
            a[i][j] = s[j];  
            if(a[i][j] == '.')cnt++; 
            else{ 
                if(cnt >= 2) col++; 
                cnt = 0; 
            }   
        }
        if(cnt >= 2) col++;  
    }
    
    for(int i = 0; i < n; i++){
        cnt = 0;  
        for(int j = 0; j < n; j++){
            if(a[j][i] == '.')cnt++; 
            else{ 
                if(cnt >= 2) row++; 
                cnt = 0; 
            } 
        }
        if(cnt >= 2) row++;  
    }
    cout << col << " " << row << "\n";  
    return 0; 
}