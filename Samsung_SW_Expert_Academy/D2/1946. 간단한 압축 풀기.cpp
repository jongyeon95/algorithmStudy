#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
    cin.tie(0);
    cout.tie(0);
    cout.sync_with_stdio(false);
	
    int test_case;
	int T,n,count,flag;
	cin>>T;
	
    for(test_case = 1; test_case <= T; ++test_case)
	{
        flag=0;
        char c;
        cin >> n;
        
        cout<<"#"<<test_case;
        
        for(int i=0; i<n; i++){
        	cin >>c >> count;
            for(int j=0; j<count; j++){
                if(flag%10==0)
                	cout<<"\n";
                cout<<c;
                flag++;
            }
        }
        cout<<"\n";
        
    }
	return 0;
}