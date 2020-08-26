#include <string>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int arr[]={0,0,0,0};
    int cnt=0;
    int flag=1;
    while(cnt<dartResult.size()){
        char c=dartResult[cnt];
        if(c=='0'){
            if(dartResult[cnt-1]=='1')
                arr[flag]=10;
        }
        else if(c=='S'){
            flag++;
        }
        else if(c=='D'){
            arr[flag]*=arr[flag];
            flag++;
            
        }
        else if(c=='T'){
            arr[flag]*=arr[flag]*arr[flag];
            flag++;
        }
        else if(c=='*'){
            arr[flag-2]*=2;
            arr[flag-1]*=2;
        }
        else if(c=='#'){
             arr[flag-1]*=-1;
        }
        else{
            arr[flag]=c-'0';
        }
        cnt++;
    }
    for(int i=1; i<=3; i++){
        answer+=arr[i];
    }
    return answer;
}