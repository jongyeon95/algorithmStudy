#include <iostream>
#include <vector>
using namespace std;
int main(){
	int n, k;
	cin >> n >> k;
	vector<int> v;
	vector<int> result;
	for (int i = 1; i <= n; ++i)
		v.push_back(i);
	int flag=-1;
	int cnt=0;
	while(cnt!=n){
		cnt++;
		flag+=k;
		if(flag>=v.size()-1){
			flag%=v.size();
		}
		result.push_back(v[flag]);
		v.erase(v.begin()+flag);
		flag--;
	}
	cout<<"<";
	for(int i=0; i<result.size()-1; i++)
		cout<<result[i]<<", ";
	cout<<result[result.size()-1]<<">";

}