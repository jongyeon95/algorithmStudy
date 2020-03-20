#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    deque<int> d;
    for(int i=0; i<operations.size(); i++){
        if(operations[i][0]=='I'){
            int temp=0;
            int flag=1;
            for(int j=operations[i].size()-1;j>1;j--){
                if(operations[i][j]=='-'){
                    temp*=-1;
                    break;
                }
                temp+=((operations[i][j]-'0')*flag);
                flag*=10;
            }
            d.push_back(temp);
            //printf("push %d \n",temp);
            sort(d.begin(),d.end());
        }
        else if(operations[i][2]!='-'&&d.size()!=0){
            //printf("pop back %d \n",d[d.size()-1]);
            d.pop_back();
        }
        else if(operations[i][2]=='-'&&d.size()!=0){
            //printf("pop front %d \n",d[0]);
            d.pop_front();
        }
    }
    if(d.size()==0){
        answer.push_back(0);
        answer.push_back(0);
    }
    else{
         answer.push_back(d.back());
         answer.push_back(d.front());
    }
    return answer;
}