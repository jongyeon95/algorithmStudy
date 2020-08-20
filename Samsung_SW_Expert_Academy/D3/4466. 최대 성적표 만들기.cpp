#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
int arr[100];

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        memset(arr,0,sizeof(arr));
        int n,k;
        int result=0;
        cin >> n >> k;
        for(int i=0; i<n; i++){
        	cin >> arr[i];
        }
        sort(arr,arr+n);
        for(int i=n-1; i>=n-k; i--){
            result+=arr[i];
        }
        cout<<"#"<<test_case<<" "<<result<<"\n";
	}
	return 0;
}