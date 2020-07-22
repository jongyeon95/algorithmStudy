#include<iostream>
#include<cmath>

using namespace std;
int arr[10];
int result,n;

void dfs(int index){
	if(index==n){
    	result++;
        return;
    }
    for(int i=0; i<n; i++){
    	bool check=true;
        for(int j=0; j<index; j++){
        	if(arr[j]==i || abs(j-index)==abs(arr[j]-i)){
            	check=false;
                break;
            }
        }
        if(check){
        arr[index]=i;
        dfs(index+1);
        }
    }
}

int main(int argc, char** argv)
{
    cin.tie(0);
    cout.tie(0);
    cout.sync_with_stdio(false);
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        result=0;
        cin>>n;
        dfs(0);
        cout<<"#"<<test_case<<" "<<result<<"\n";

	}
	return 0;
}