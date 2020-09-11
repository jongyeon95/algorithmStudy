#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int totalStory;
int startFloor;
int goalFloor;
int upCount;
int downCount;
bool check[1000001];


int main(){
	cin>>totalStory>>startFloor>>goalFloor>>upCount>>downCount;
	queue<pair<int ,int>> q;
	memset(check,false,sizeof(check));
	int result=-1;
	q.push({startFloor,0});
	while(!q.empty()){
		pair<int,int> p=q.front();
		q.pop();
		if(p.first==goalFloor){
			cout<<p.second;
			return 0;
		}

		int tUp=p.first+upCount;
		int tDown=p.first-downCount;
		
		if(!check[tUp]&&tUp<=totalStory){
			check[tUp]=true;
			q.push({tUp,p.second+1});
		}

		if(!check[tDown]&&tDown>=1){
			check[tDown]=true;
			q.push({tDown,p.second+1});
		}

	}
	cout<<"use the stairs";


}