#include <string>
 
using namespace std;
 
int solution(string s) {
    int answer = s.length();
 
    if(s.length() == 1)
        return 1;
 
    for(int i = 1; i <= s.length() / 2; i++){ 
        int count = 1;
        string preStr = s.substr(0, i);
        string cmp, answerStr;
 
        for(int j = i; j < s.length(); j += i){ 
            cmp = s.substr(j, i);
 
            if(!(preStr.compare(cmp)))
                count++;
            else{
                if(count == 1){
                    answerStr += preStr;
                    preStr = cmp;
                }else{
                    answerStr = answerStr + to_string(count) + preStr;
                    preStr = cmp;
                    count = 1;
                }
            }
            
            if(j + i >= s.length()){
                if(count != 1){
                    answerStr = answerStr + to_string(count) + preStr;
                    break;
                }else{
                    answerStr = answerStr + s.substr(j);
                    break;
                }
            }
        }
        answer = (answer > answerStr.length()) ? answerStr.length() : answer;
    }
    return answer;
}
