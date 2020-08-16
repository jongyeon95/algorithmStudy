#include <iostream>

using namespace std;

long long Answer;

int main(int argc, char** argv)
{
	int T, test_case;


	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 0;
	    int n;
	    cin >> n;
	    long long arr[n];
	    
	    for(int i=0; i<n; i++){
	        cin >> arr[i];
	    }
	    long long num=arr[n-1];
	    for(int i=1; i<n; i++){
	       if(arr[i]-arr[i-1]<num)
	        num=arr[i]-arr[i-1];
	    }
	    for(int i=1; i<=num; i++){
	       if(num%i==0)
	        Answer++;
	    }
	    
	    if(Answer==0)
	        Answer++;
	    
	   
	    
	
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;
}