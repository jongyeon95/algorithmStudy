#include<iostream>
#include<cstring>

using namespace std;

int busStop[5001];

int main(int argc, char** argv)
{
    cin.tie(0);
    cout.sync_with_stdio(false);
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        memset(busStop,false,sizeof(busStop));
        int n,a,b,p,temp;
        cin >> n;
        for(int i=0; i<n; i++){
        	cin >> a >>b;
            for(int j=a; j<=b; j++){
            	busStop[j]++;
            }
        }
        cin >> p;
        cout<<"#"<<test_case<<" ";
        for(int i=0; i<p; i++){
        	cin >> temp;
            cout<<busStop[temp]<<" ";
        }
        cout<<"\n";
		
	}
	return 0;
}