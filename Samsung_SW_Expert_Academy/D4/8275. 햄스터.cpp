#include<iostream>
#include<cstring>
using namespace std;
int arr[6];
int resultArr[6];
int command[10][3];
int n,x,m; // N우리수 , X마리 M 조건
int maxHam;

bool check(){
    for(int i=0; i<m; i++){
        int temp=0;
    	for(int j=command[i][0]-1; j<command[i][1]; j++){
        	temp+=arr[j];
        }
        if(temp!=command[i][2])
            return false;
    }
    return true;
}

void dfs(int cnt){
    
    if(cnt==n){
        if(check()){
            int temp=0;
            for(int i=0; i<n; i++){
                temp+=arr[i];
            }
            if(maxHam<temp){
                maxHam=temp;
                for(int i=0; i<n;i++){
                    resultArr[i]=arr[i];
                }
            }
        }
      return;
    }
    
	for(int i=0; i<=x; i++){  
        arr[cnt]=i;
        dfs(cnt+1);
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
        maxHam=-1;
         memset(arr,0,sizeof(arr));
        memset(command,0,sizeof(command));
        cin >> n >> x >> m;
        for(int i=0; i<m; i++){
            cin >> command[i][0] >> command[i][1] >> command[i][2];
        }
        
        dfs(0);
        cout<<"#"<<test_case<<" ";
        if(maxHam==-1){
        	cout<<"-1\n";
        }
        else{
        	for(int i=0; i<n; i++)
                cout<<resultArr[i]<<" ";
            cout<<"\n";
        } 
		
	}
	return 0;
    
}