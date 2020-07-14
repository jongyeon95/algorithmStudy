#include<iostream>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T,n,a,b;
    int minN,maxN;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{

        scanf("%d %d %d",&n,&a,&b);
        
        if(a+b<=n){
            minN=0;
            maxN=min(a,b);
        }
        else{
                maxN=min(a,b);
                minN=a+b-n;
        }
        cout<<"#"<<test_case<<" "<<maxN<<" "<<minN<<"\n";
       
	}
	return 0;
}