#include<iostream>
using namespace std;
int day[]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int main(int argc, char** argv)
{
    cin.tie(0);
    cout.tie(0);
    cout.sync_with_stdio(false);

	int test_case;
	int T;
    int M1,M2,D1,D2;

	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int result=0;
        cin >> M1 >> D1>> M2 >> D2;
        
        for(int i=M1; i<=M2; i++){
            if(i==M2){// 마지막 월은 D2입력값을 더하고 D1 값을 빼준다.
            	result+=D2-D1+1;
                continue;
            }
        	result+=day[i];
        }
        cout<<"#"<<test_case<<" "<<result<<"\n";
        
	}
	return 0;
}