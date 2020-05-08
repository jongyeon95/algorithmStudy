#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    for(int i=0; i<skill_trees.size();i++){
        bool skillCheck=true;
        int flag=0;
        for(int j=0; j<skill_trees[i].size();j++){
            bool check=false;
            if(skill[flag]==skill_trees[i][j]){
                flag++;
                continue;
            }
            for(int k=flag; k<skill.size(); k++){
                if(skill[k]==skill_trees[i][j]){
                    check=true;
                    break;
                }
            }
            if(check){
                skillCheck=false;
                break;
            }
        }
        if(skillCheck)
            answer++;
    }
    return answer;
}