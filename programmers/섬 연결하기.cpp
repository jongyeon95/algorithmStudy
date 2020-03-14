#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int d[101];

int find(int node){
    if(node == d[node]) return node;
    else return d[node] = find(d[node]);
}

bool cmp(const vector<int> &a, const vector<int> &b){
    return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    for(int i=0; i<n; i++){ 
        d[i] = i;
    }
  
    sort(costs.begin(), costs.end(), cmp);
   
    for(int i=0; i<costs.size(); i++){
        int start = find(costs[i][0]);
        int end = find(costs[i][1]);
        int cost = costs[i][2];
   
        if(start != end){
            d[start] = end;
            answer += cost;
        }
    }
    
    return answer;
}