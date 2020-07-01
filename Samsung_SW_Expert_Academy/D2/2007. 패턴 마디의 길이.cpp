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
        int L=2;
        while(1){
            bool check=true;
         
            for(int i=0; i<30-L; i++){
                if(s[i]!=s[i+L]){
                    check=false;
                    break;
                }
            }
            if(check){
                cout <<"#"<<test_case<<" "<<L<<"\n";
                break;
            }
            L++;
        }
	}
	return 0;
}