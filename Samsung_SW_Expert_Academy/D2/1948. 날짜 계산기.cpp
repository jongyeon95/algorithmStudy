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
        
        result=day[M1]-D1+1;// 시작 월 
        for(int i=M1+1; i<=M2; i++){
            if(i==M2){// 마지막 월은 입력값만 더한다.
            	result+=D2;
                continue;
            }
        	result+=day[i];
        }
        cout<<"#"<<test_case<<" "<<result<<"\n";
        
	}
	return 0;
}