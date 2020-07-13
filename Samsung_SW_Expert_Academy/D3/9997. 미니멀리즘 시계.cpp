#include<iostream>
using namespace std;
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int time;
        int hour,minute;
        cin >> time;
        hour=time/30;
        minute=(time-hour*30)*2;
        cout<<"#"<<test_case<<" "<<hour<<" "<<minute<<"\n";
        
	}
	return 0;
}