#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int n,k;
        int result=0;
        cin >> n >> k;
        if(n%k!=0)
            result=1;
        cout<<"#"<<test_case<<" "<<result<<"\n";
            
	}
	return 0;
}