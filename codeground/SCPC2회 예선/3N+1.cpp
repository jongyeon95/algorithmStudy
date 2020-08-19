#include <iostream>

using namespace std;

int Answer;
int k;
unsigned long long minN,maxN;

void go(unsigned long long num, unsigned long long cnt){
    if(cnt==k){
        if(minN>num)
            minN=num;
        if(maxN<num)
            maxN=num;
        return;
    }
    
    go(2*num,cnt+1);
    
    if(num%3!=0&&((num-1)/3)%2!=0&&(num-1)%3==0&&(num-1)/3>1)
        go((num-1)/3,cnt+1);
    
}


int main(int argc, char** argv)
{
	int T, test_case;


	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
	    cin >> k;
	    maxN=0;
	    minN=0xffffff;

		Answer = 0;
		go(1,0);
	
		cout << "Case #" << test_case+1 << endl;
		cout <<minN<<" "<<maxN<<endl;
	}

	return 0;
}