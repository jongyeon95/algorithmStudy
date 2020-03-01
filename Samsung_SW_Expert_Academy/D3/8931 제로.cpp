#include <iostream>
#include <vector>
using namespace std;
int main(){
	int TC;
	scanf("%d",&TC);
	for (int t = 1; t <= TC; t++)
	{
		int result=0;
		int k,temp;
		vector<int> v;
		scanf("%d",&k);
		while(k--){
			scanf("%d",&temp);
			if (temp==0&&v.size()!=0)
			{
				v.pop_back();
			}
			else
				v.push_back(temp);
		}
		for (int i = 0; i < v.size(); ++i)
		{
			result+=v[i];
		}

		printf("#%d %d\n",t,result);
	}
}