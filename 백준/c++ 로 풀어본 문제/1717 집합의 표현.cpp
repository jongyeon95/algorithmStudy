#include <iostream>
using namespace std;
int parentArr[1000001];
int n,m;
void input(){
	cin >> n >> m;
	for (int i = 0; i <=n; ++i)
	{
		parentArr[i]=i;
	}
}

int Find(int p){
	if(p==parentArr[p]){
		return p;
	}
	else{
		int np= Find(parentArr[p]);
		parentArr[p]=np;
		return np;
	}
}

void Union(int a, int b){
	int na=Find(a);
	int nb=Find(b);
	parentArr[nb]=na;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	input();
	for (int i = 0; i < m; ++i)
	{
		int command,a,b;
		cin >> command >> a >> b;
		if(command==0){
			
			Union(a,b);
			
		}
		else{
			int ap=Find(a);
			int bp=Find(b);
			if(ap!=bp){
				cout<<"NO\n";
			}
			else
				cout<<"YES\n";
		}
	}

}