#include <string>
#include <vector>
using namespace std;


inline bool check(char a, char b) { 
    if(a >= 65 && b >= 65 && a <= 90 && b <= 90)
       return true;
    return false;
}

int solution(string str1, string str2) {

	int answer = 0;
	vector <pair<char, char>> v1, v2;

	for (int i = 0; i < str1.size();i++) {
        
		if (str1[i] >= 97 && str1[i] <= 122) 
            str1[i] -= 32;
        
		if (i != 0) 
            if (check(str1[i], str1[i - 1])) 
                v1.push_back({str1[i - 1], str1[i]});

	}

	for (int i = 0; i < str2.size();i++) {

		if (str2[i] >= 97 && str2[i] <= 122) 
            str2[i] -= 32;

		if (i != 0) 
            if (check(str2[i], str2[i - 1])) 
                v2.push_back({str2[i - 1], str2[i]});

	}

	if (v1.size() == 0 && v2.size() == 0) return 65536;

	int num = v1.size() + v2.size(); int num2 = 0;
	for (int i = 0; i < v1.size(); i++) {
		for (int j = 0; j < v2.size(); j++) {
			if (v1[i].first == v2[j].first && v1[i].second == v2[j].second) {
				num2++; 
                v2.erase(v2.begin() + j);
                break;
			}
        }
	}

	num -= num2;
    
	float result = ((float)num2 / (float)num) * 65536;
        
	answer = (int)result;

	return answer;

}