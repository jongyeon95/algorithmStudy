#include<iostream>
#include<cstring>
using namespace std;

int main(int argc, char** argv)
{
    int arr[100];
    int score[10001];
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int n;
        int sum=0;
        int ans=0;
        cin >> n;
        memset(arr,0,sizeof(arr));
        memset(score,0,sizeof(score));
        
        score[0]=1; // 0은 항상 존재
        
        for(int i=0; i<n; i++){
            cin >> arr[i];
            sum+=arr[i];
            for(int j=sum; j>=0; j--)
                if(score[j]>0)
                    score[j+arr[i]]++;      
        }
             
        // 중복을 제외한 값 찾기
        for(int i=0; i<=sum; i++)
        	if(score[i]>0)
                ans++;
            
        cout <<"#"<<test_case<<" "<<ans<<"\n";
       
	}
	return 0;
}