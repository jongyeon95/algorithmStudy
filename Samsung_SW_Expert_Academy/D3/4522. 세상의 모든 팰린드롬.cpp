#include<iostream>
#include<string>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        string s;
        cin >> s;
        bool check=true;
        for(int i=0; i<s.size()/2; i++){
            if(s[i]!=s[s.size()-1-i]){
                if(s[i]=='?'||s[s.size()-1-i]=='?')
                    continue;
                check=false;
                break;
            }
        }
        cout<<"#"<<test_case<<" ";
        if(check)
            cout<<"Exist\n";
        else
            cout<<"Not exist\n";

	}
	return 0;
}