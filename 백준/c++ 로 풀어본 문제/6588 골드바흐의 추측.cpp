#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;
bool check[1000001];
vector<int> v;

void init(){
	memset(check,false,sizeof(check));
	for (int i = 2; i <= sqrt(1000001); ++i)
	{
		if(check[i])
			continue;
		v.push_back(i);
		for(int j=i+i; j<1000001; j+=i){
			check[j]=true;
		}
	}
	
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cout.tie(0);
	int cnt;
	init();
	while(1){
		cin >> cnt;
		if(cnt==0)
			break;
		bool findNum=false;
		for(int i=0; i<v.size()-1;i++){
			int a=v[i];
			int b=cnt-v[i];
			if(!check[b]){
				cout<< cnt << " = " << a << " + " << b << "\n";
				findNum=true;
				break;
			}
		}
		if(!findNum)
			cout << "Goldbach's conjecture is wrong.\n";
	}


}