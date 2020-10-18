#include <iostream>
#include <deque>
using namespace std;
int main(){
	deque<pair<int,bool>> belt;
	int n,k;
	cin >> n >> k;
	for (int i = 0; i < n*2; ++i)
	{
		int temp;
		cin >> temp;
		belt.push_back({temp,false});
	}
	int endCnt=0;
	int endTime=0;
	while(1){
		endTime++;
		belt.push_front(belt.back());
		belt.pop_back();
		belt[0].second=false;
		belt[n-1].second=false;
		for(int i=n-1; i>0; i--){
			if(belt[i].second==false&&belt[i].first>0){
				if(belt[i-1].second==true){
					belt[i-1].second=false;
					belt[i].second=true;
					belt[i].first--;
					if(belt[i].first==0){
						endCnt++;
					}
				}
			}
		}
		if(belt[0].second==false&&belt[0].first>0){
			belt[0].second=true;
			belt[0].first--;
			if(belt[0].first==0){
					endCnt++;
			}

		}
		if(endCnt>=k){
			break;
		}
	}
	cout<<endTime;
}