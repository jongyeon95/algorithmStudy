#include<iostream>
using namespace std;

int scoreArr[12];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int T,N,playerScore,Result,i;
    cin>>T;

    for(int t = 1; t <= T; ++t)
    {
        playerScore=0, Result=0;

        for(i=2; i<=11; i++)
            scoreArr[i]=4;
        scoreArr[10]=16;

        cin >> N;

        int temp;

        //현재 플레이어의 점수 입력
        for(i=0; i<N; i++){
            cin >>temp;
            scoreArr[temp]--;
            playerScore+=temp;
        }

        //현재 플레이어의 점수와 다음 카드의 합과 21의 비교
        for(i=2; i<=11; i++)
            if(playerScore+i<=21)
                Result+=scoreArr[i];
            else
                Result-=scoreArr[i];
    
        if(Result>0)
            cout<<"#"<<t<<" "<<"GAZUA\n";
        else
            cout<<"#"<<t<<" "<<"STOP\n";

    }
    return 0;
}