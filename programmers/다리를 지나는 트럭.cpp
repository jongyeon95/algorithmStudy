#include <string>
#include <queue>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int truckFlag=0;
    int bWeight=0;
    queue<int> q;
    while(bridge_length--){
        q.push(0);
    }
    while(!q.empty()){
        bWeight-=q.front();
        q.pop();
        answer++;
        if(truckFlag==truck_weights.size())
            continue;
        if(bWeight+truck_weights[truckFlag]>weight){
            q.push(0);
        }
        else{
            q.push(truck_weights[truckFlag]);
            bWeight+=truck_weights[truckFlag];
            truckFlag++;
        }
       
    }
    return answer;
}