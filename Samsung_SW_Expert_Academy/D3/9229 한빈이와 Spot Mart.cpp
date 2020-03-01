#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
	int testcase;
	scanf("%d",&testcase);
	for (int t = 1; t <= testcase; ++t)
	{
		int n,m;
		int result=0;
		vector<int> v;
		scanf("%d %d",&n,&m);
		for (int i = 0; i < n; ++i)
		{
			int temp;
			scanf("%d",&temp);
			if(!(temp>=m))
				v.push_back(temp);
		}
		bool findAnswer=false;
		sort(v.begin(),v.end());
		for (int i = v.size()-1; i >0; i--){
			for (int j = 0; j < i; ++j){
				if(v[i]+v[j]>result&&v[i]+v[j]<=m)
					result=v[i]+v[j];
				if(v[i]+v[j]==m){
					result=m;
					findAnswer=true;
					break;
				}

			}
			if(findAnswer)
				break;
		}
		if(result!=0)
			printf("#%d %d\n",t,result);
		else
			printf("#%d -1\n",t);
	}

	

	return 0;
}