#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int main(){
	bool vidited[100001];
	memset(vidited,false,sizeof(vidited));
	int x,y;
	queue<pair<int,int>> q;
	cin >> x >> y;
	vidited[x]=true;
	q.push({x,0});
	while(!q.empty()){
			int X=q.front().first;
			int Y=q.front().second;
			q.pop();
			if(X==y){
				cout << Y;
				return 0;
			}
			if(X+1<=100000&&!vidited[X+1]){
					vidited[X+1]=true;
					q.push({X+1,Y+1});
				}
			if(X-1>=0&&!vidited[X-1]){
					vidited[X-1]=true;
					q.push({X-1,Y+1});
				}
			if(X*2<=100000&&!vidited[X*2]){
					vidited[X*2]=true;
					q.push({X*2,Y+1});
				}
			
		}
	}

