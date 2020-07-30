#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
    cin.tie(0);
    cout.sync_with_stdio(false);
    cout.precision(6);
	int test_case;
	int T;
	
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int n;
        cin >> n;
        double a,b,result;
        result=0.0;
        for(int i=0; i<n; i++){
            cin >> a >> b;
            result+=(a*b);
        }
        cout << fixed;
        cout<<"#"<<test_case<<" "<<result<<"\n";

	}
	return 0;
}