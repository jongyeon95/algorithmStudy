#include<iostream>
using namespace std;
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int n;
        int result=0;
        cin >> n;
        if(n%2==0)
            result=-(n/2);
        else
            result=(n/2)+1;
        cout <<"#"<<test_case<<" "<<result<<"\n";

	}
	return 0;
}