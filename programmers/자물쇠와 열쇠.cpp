#include <string>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;
int lockMap[60][60];
vector<pair<int,int>> noBlock;
int keySize;
int lockSize;

void rotate(vector<vector<int>> &key){
    int m = key.size();
    vector<vector<int>> temp(m, vector<int>(m, 0));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            temp[i][j] = key[m - j - 1][i];
        }
    }
    key = temp;
    return;
}

bool checkLcokMap(){
    for(int i=0; i<noBlock.size(); i++){
        if(lockMap[noBlock[i].first][noBlock[i].second]==0){
            return false;
        }
    }
    return true;
}

void resetLockMap(){
     for(int i=0; i<noBlock.size(); i++){
        lockMap[noBlock[i].first][noBlock[i].second]=0;
    }
}


bool solved(vector<vector<int>> k){
    vector<vector<int>> key;
    key.assign(k.begin(),k.end());
    for(int i=0; i<4; i++){
        rotate(key);
       
        for(int i=1; i<lockSize*2; i++){
            for(int j=1; j<lockSize*2; j++){
                
                bool check=false;
                for(int ki=0; ki<keySize; ki++){
                    for(int kj=0; kj<keySize; kj++){
                        if(lockMap[ki+i][kj+j]==1&&key[ki][kj]==1){
                            check=true;
                            break;
                        }
                        if(ki+i>=lockSize&&kj+j>=lockSize&&ki+i<lockSize*2&&kj+j<lockSize*2)
                            lockMap[ki+i][kj+j]+=key[ki][kj];
                    }
                    if(check)
                        break;
                }
                
                if(!check){
                    if(checkLcokMap())
                        return true;
                }
                
                resetLockMap();
                                 
            }
        }   
                   
        
    }
    return false;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    memset(lockMap,0,sizeof(lockMap));
    lockSize=lock.size();
    keySize=key.size();
    for(int i=0; i<lockSize; i++){
        for(int j=0; j<lockSize; j++){
            lockMap[i+lockSize][j+lockSize]=lock[i][j];
            if(lock[i][j]==0){
                noBlock.push_back({i+lockSize,j+lockSize});
            }
        }
    }

    
    return solved(key);
}