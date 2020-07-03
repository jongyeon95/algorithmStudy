#include<iostream>
#include<string>

using namespace std;

int main(int argc, char** argv)
{
    string g[]={"A+","A0","A-","B+","B0","B-","C+","C0","C-","D0"};
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int n,k;
        double sum[100];
        int mid,last,report;
        int result=0;
        cin >> n >> k;
        for (int i = 0; i<n; i++){
            cin>>mid>>last>>report;
            sum[i] = mid * 0.35 + last * 0.45 + report * 0.2;
        }
        for (int i = 0; i<n; i++){
            if (sum[i] > sum[k - 1])
                result++;
        }
        cout <<"#"<<test_case<<" "<<g[result/(n/10)]<<"\n";

	}
	return 0;
}