#include<iostream>

using namespace std;

int arr[100000];
int n;
int main(int argc, char** argv)
{
    cin.tie(0);
    cout.sync_with_stdio(false);
	int test_case;
	int T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        
        cin >>n;
        int avg=0; //평균
        int result=0;
        for(int i=0; i< n; i++){
        	cin >> arr[i];
            avg+=arr[i];
        }
        avg/=n;
        for(int i=0; i<n; i++){
        	if(arr[i]<=avg)
                result++;
        }
        
        cout<<"#"<<test_case<<" "<<result<<"\n";

	}
	return 0;
}