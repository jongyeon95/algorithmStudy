#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

struct coordinate
{
	int x;
	int y;
	
};

bool cangoing(coordinate present, coordinate togo ){
	int x;
	int y;
	x=abs(present.x-togo.x);
	y=abs(present.y-togo.y);
	if(x+y<=1000)
		return true;
	return false;
}

int main(){
	int testcase;
	cin >> testcase;
	while(testcase--){
		int n;
		cin >> n;
		bool can=false;
		coordinate sangGeun;
		coordinate store[n];
		coordinate festival;
		queue<coordinate> q;
		bool visited[n];
		memset(visited,false,sizeof(visited));
		cin >> sangGeun.x >> sangGeun.y;
		for (int i = 0; i < n; ++i)
			cin >> store[i].x >> store[i].y;
		cin >> festival.x >> festival.y;
		q.push(sangGeun);
		while(!q.empty()){
			coordinate c= q.front();
			q.pop();

			if (cangoing(c,festival))
			{
				can=true;
				break;
			}

			for (int i = 0; i < n; ++i)
			{
				if(!visited[i]&&cangoing(c,store[i])){
					q.push(store[i]);
					visited[i]=true;
				}
			}
		}

		if (can)
		{
			cout << "happy\n";
		}
		else 
			cout <<"sad\n";
		
	}
}