#include<iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T,n;
    cin>>T;
    for(int test_case = 1; test_case <= T; ++test_case)
    {
        cin >> n;
        cout<<"#"<<test_case<<" ";
        if(n<100)
            cout<<"0\n";
        else if(n<1000)
            cout<<"1\n";
        else if(n<10000)
            cout<<"2\n";
        else if(n<100000)
            cout<<"3\n";
        else if(n<1000000)
            cout<<"4\n";
        else
            cout<<"5\n";
    }
    return 0;
}