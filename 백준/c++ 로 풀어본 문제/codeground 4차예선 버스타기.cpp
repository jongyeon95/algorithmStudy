
#include <iostream>
#include <algorithm>
using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case;
	

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 1;
		int n,k;
		cin >> n >>k;
		int people[n];
		for(int i=0; i<n; i++){
		    cin >> people[i];
		}
		sort(people,people+n);
		for(int i=1; i<n;i++){
		    if(people[i]-people[i-Answer]<=k){
		        Answer++;
		    }
		}
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}