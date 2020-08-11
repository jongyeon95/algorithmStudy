#include<iostream>
#include<cstring>
#include<string>
#include<vector>
using namespace std;

bool visited[15];
int alphabet[26];
vector<string> words;
int n;
int result;

//알파벳 넣기
void alphabetAdd(string s){
    for(int i=0; i<s.size();i++){
    	alphabet[s[i]-'a']++;
    }
}

//알파벳 빼기
void alphabetSub(string s){
    for(int i=0; i<s.size();i++){
    	alphabet[s[i]-'a']--;
    }
}

//알파벳 다있는지 확인
bool alphabetCheck(){
    for(int i=0; i<26;i++){
    	if(alphabet[i]<1)
            return false;
    }
    return true;
}

//모든 경우의 수 
void dfs(int index){
    if(index==words.size())
        return;
    
	for(int i=index; i<words.size(); i++){
        alphabetAdd(words[i]);
        if(alphabetCheck())
            result++;
        dfs(i+1);
        alphabetSub(words[i]);
    }
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
    
 
	
    for(test_case = 1; test_case <= T; ++test_case)
	{
        result=0;
        memset(visited,false,sizeof(visited));
        memset(alphabet,0,sizeof(alphabet));
        words.clear();
        cin>>n;
        for(int i=0; i<n; i++){
        	string s;
            cin>>s;
            words.push_back(s);
        }
        dfs(0);
        cout<<"#"<<test_case<<" "<<result<<"\n";
        
	}
	return 0;
}