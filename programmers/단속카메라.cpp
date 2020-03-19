#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    int lastflag=-30000;
    sort(routes.begin(),routes.end());
    for(int i=0; i<routes.size();i++){
        if(routes[i][0]>lastflag){
            answer++;
            lastflag=routes[i][1];
        }
        else if(routes[i][1]<lastflag)
            lastflag=routes[i][1];
    }
    return answer;
}