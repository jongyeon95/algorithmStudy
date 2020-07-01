#include<iostream>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int n, m;
        cin >> n >> m;
        int arr[n][n];
        int result=0;
        for(int i=0; i<n; i++){
        	for(int j=0; j<n; j ++){
            	cin >> arr[i][j];
            }
        }
        
         for(int x=0; x<=n-m; x++){
        	for(int y=0; y<=n-m; y++){
                int tResult=0;
            	for(int i=x; i<x+m; i++){
                	for(int j=y; j<y+m; j++){
                    	tResult+=arr[i][j];
                    }
                }
                if(tResult>result)
                    result=tResult;
            }
        }
        
        cout<<"#"<<test_case<<" "<<result<<"\n";
	}
	return 0;
}