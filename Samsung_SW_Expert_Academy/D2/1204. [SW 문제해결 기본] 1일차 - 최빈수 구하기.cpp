#include<iostream>
#include<cstring>
using namespace std;

int main(int argc, char** argv)
{
    cin.tie(0);
    cout.tie(0);
    cout.sync_with_stdio(false);
	int test_case;
	int T;
	cin>>T;
	int arr[101];
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin>>test_case;
        memset(arr,0,sizeof(arr));
        int temp;
        int max=0;
        int maxIndex=0;
        for(int i=0; i<1000; i++){
            cin >> temp;
            arr[temp]++;
            if(arr[temp]>max){    
            	max=arr[temp];
            }        
        }
        for(int i=100; i>=0; i--){
        	if(max==arr[i]){
            	maxIndex=i;
                break;
            }
                
        }
        cout<<"#"<<test_case<<" "<<maxIndex<<"\n";

	}
	return 0;
}