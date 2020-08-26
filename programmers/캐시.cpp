#include <string>
#include <vector>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    int frontIndex=0;
    vector<string> cacheArr;
    if(cacheSize==0){
        return cities.size()*5;
    }
    for(int i=0; i<cities.size(); i++){
        for(int j=0; j<cities[i].size();j++){
            if(cities[i][j]<97){
                cities[i][j]+=32;
            }
        }
    }
    cacheArr.resize(cacheSize);
    for(int i=0; i<cities.size();i++){
        bool check=false;
       for(int j=0; j<cacheSize;j++){
           if(cities[i]==cacheArr[j]){
               check=true;
               cacheArr.push_back(cities[i]);
               cacheArr.erase(cacheArr.begin()+j);
               break;
           }
       }
        if(check){
            answer+=1;
        }
        else{
            answer+=5;
            cacheArr.erase(cacheArr.begin());
            cacheArr.push_back(cities[i]);
        }
    }
    
    return answer;
}