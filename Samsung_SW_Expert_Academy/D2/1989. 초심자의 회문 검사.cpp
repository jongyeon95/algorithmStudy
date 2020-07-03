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
        //회문 판별
        for(int i=0; i<s.size()/2; i++){
            if(s[i]!=s[s.size()-1-i]){
                check=false;
                break;
            }
        }
        cout<<"#"<<test_case<<" "<<check<<"\n";
    }
    return 0;
}