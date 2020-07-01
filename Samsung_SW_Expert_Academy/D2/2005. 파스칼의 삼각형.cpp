#include<iostream>
#include<cstring>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
    int arr[12][12];
    memset(arr,0,sizeof(arr));
   
    for(int i=1; i<=10; i++){
        for(int j=1; j<=i; j++){
            if(j==1){
            	arr[i][j]=1;
                continue;
            }
            else{
                arr[i][j]+=arr[i-1][j-1]+arr[i-1][j];
            }
        }
    }
    
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int n;
        cin >> n;
        cout<<"#"<<test_case<<"\n";
        for(int i=1; i<=n; i++){
        	for(int j=1; j<=i; j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<"\n";
        }
	}
	return 0;
}