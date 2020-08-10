#include<iostream>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
    cin.tie(0);
	int test_case;
    int arr[100];
	for(test_case = 1; test_case <= 10; ++test_case)
	{
        int dump;
        cin >> dump;
        for(int i=0; i<100; i++){
        	cin >> arr[i];
        }
        sort(arr,arr+100);
        while(dump--){
            if(arr[99]-arr[0]<=1)
                break;
            arr[99]--;
            arr[0]++;
            sort(arr,arr+100);
        }
        cout<<"#"<<test_case<<" "<<arr[99]-arr[1]<<"\n";


	}
	return 0;
}