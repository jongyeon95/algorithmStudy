#include<iostream>
#include<algorithm>
using namespace std;

int main(int argc, char** argv)
{
    cin.tie(0);
    cout.sync_with_stdio(false);
	int test_case;
	int T;
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int n,k;
        cin >> n >> k;
        int arr[n];
        for(int i=0; i<n; i++){
        	cin >> arr[i];
            if(i!=0){
            	arr[i-1]=arr[i]-arr[i-1];
            }
        }
        int result=0;
        sort(arr,arr+n-1);
        for(int i=n-k-1; i>=0; i--){
        	result+=arr[i];
        }
        cout<<"#"<<test_case<<" "<< result<<"\n";
        
        

	

	}
	return 0;
}