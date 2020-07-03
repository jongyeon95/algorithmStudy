#include<iostream>
#include<algorithm>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int n;
        cin >> n;
        int arr[n];
        for(int i=0; i<n; i++){
            scanf("%d",&arr[i]);
        }
        sort(arr,arr+n);
        printf("#%d",test_case);
        for(int i=0; i<n; i++){
             printf(" %d",arr[i]);
        }
         printf("\n");
	}
	return 0;
}