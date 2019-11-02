#include <iostream>
#include <vector>
using namespace std;
int arr[20][20];
bool check[20];
int n;
int result=99999;

void go(int index,int cnt){
	if(cnt==n/2){
		vector<int> star,links;

		for (int i = 0; i < n; i++)
		{
			if(check[i]){
				star.push_back(i);
			}
			else{
				links.push_back(i);
			}
			
		}

		int sy,sx,lx,ly;
		int star_sum=0;
		int links_sum=0;
		for (int i = 0; i < star.size(); i++)
		{
			for (int j = i+1; j < star.size(); j++)
			{
				sy=star[j];
				sx=star[i];
				ly=links[j];
				lx=links[i];
				star_sum+=arr[sy][sx]+arr[sx][sy];
				links_sum+=arr[ly][lx]+arr[lx][ly];
			}
		}
		result=min(result,abs(star_sum-links_sum));
		return;

	}
	else{
		for(int i=index+1; i<n;i++){
			if(!check[i]){
			check[i]=true;
			go(i,cnt+1);
			check[i]=false;
			}
		}
	}
}


int main(){
	
	cin >> n ;
	result=9999999;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin >> arr[i][j];
			}
		}
	go(0,0);
	cout << result;


}