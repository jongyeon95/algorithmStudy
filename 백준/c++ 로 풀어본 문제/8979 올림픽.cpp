#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Olympiad
{
	int id;
	int g;
	int s;
	int b;
	int score;
};

bool cmp(Olympiad a, Olympiad b){
	if(a.g>b.g)
		return true;
	else if(a.g==b.g){
		if(a.s>b.s)
			return true;
		else if(a.s==b.s){
			if(a.b>b.b)
				return true;
		}
	}
	return false;
}

int main(){
	int n,k;
	vector<Olympiad> v;
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
	{
		int id,g,s,b;
		cin >> id >> g >> s >>b;
		v.push_back({id,g,s,b,0});
	}
	sort(v.begin(),v.end(),cmp);
	v[0].score=1;
	for (int i = 1; i < v.size(); ++i)
	{
		if(v[i].g==v[i-1].g && v[i].s==v[i-1].s && v[i].b==v[i-1].b){
			v[i].score=v[i-1].score;
		}
		else
			v[i].score=i+1;

		if(v[i].id==k){
			cout<<v[i].score;
			return 0;
		}
	}
	cout<<v[0].score;


}