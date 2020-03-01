#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int a,b,c;
bool check[201][201];
bool checkWater[201];
struct water
{
	int a,b,c;
};

void bfs(){
queue<water> q;
q.push({0,0,c});
	while(!q.empty()){
		water w=q.front();
		q.pop();

		if(check[w.a][w.b])
			continue;
		check[w.a][w.b]=true;

		if(w.a==0){
			checkWater[w.c]=true;
		}
		// a to b

		if(w.a+w.b<=b){
			q.push({0,w.a+w.b,w.c});
		}
		else{
			q.push({w.a+w.b-b,b,w.c});
		}

		// a to c 
		if(w.a+w.c<=c){
			q.push({0,w.b,w.c+w.a});
		}
		else{
			q.push({w.a+w.c-c,w.b,c});
		}

		//b to a
		if(w.a+w.b<=a){
			q.push({w.a+w.b,0,w.c});
		}
		else{
			q.push({a,w.a+w.b-a,w.c});
		}

		//b t0 c
		if(w.b+w.c<=c){
			q.push({w.a,0,w.c+w.b});
		}
		else{
			q.push({w.a,w.b+w.c-c,c});
		}

		// c to a
		if(w.c+w.a<=a){
			q.push({w.c+w.a,w.b,0});
		}
		else{
			q.push({a,w.b,w.c+w.a-a});
		}
		// c to b
		if(w.c+w.b<=b){
			q.push({w.a,w.c+w.b,0});
		}
		else{
			q.push({w.a,b,w.b+w.c-b});
		}

	}
}

int main(){
	cin >> a >> b >> c;
	memset(check,false,sizeof(check));
	memset(checkWater,false,sizeof(checkWater));

	bfs();


	for (int i = 0; i <= c; ++i)
	{
		if(checkWater[i])
			cout << i <<" ";
		
	}


}