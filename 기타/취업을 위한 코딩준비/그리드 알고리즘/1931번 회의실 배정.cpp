#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;



struct conference
{
	int start;
	int end;
};
bool cmp( conference a,conference b){
	if(a.end==b.end)
		return a.start<b.start;
	else
		return a.end<b.end;
}

int main(){

int n;
int temp=0;;
int result=0;
cin >> n;
vector<conference> c(n);
for(int i=0;i<n;i++){
	cin>>c[i].start>>c[i].end;
}
sort(c.begin(),c.end(),cmp);
for(int i=0;i<n;i++){
	if(c[i].start>=temp){
		temp=c[i].end;
		result++;
	}
	}
	cout<<result;

}
