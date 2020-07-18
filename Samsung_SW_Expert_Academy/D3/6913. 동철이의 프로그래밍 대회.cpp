#include<iostream>
using namespace std;

int main()
{
    cin.tie(0); 
    cout.tie(0);
    cout.sync_with_stdio(false);
	int test_case;
	int T,N,M,max,victory;
	cin>>T;
	int score[20];
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> N >> M;
        int temp;
        max=0 , victory=0;

        for(int i=0; i<N; i++){
            score[i]=0;//초기화
        	for(int j=0; j<M; j++){
                cin >> temp;
                score[i]+=temp;
            }
            if(score[i]>max)
                max=score[i];//최대값 갱신
        }
        
        for(int i=0; i<N; i++){
        	if(score[i]==max)
                victory++;//1등 수 
        }
        
        cout <<"#"<<test_case<<" "<<victory<<" "<<max<<"\n";

	}
	return 0;
}