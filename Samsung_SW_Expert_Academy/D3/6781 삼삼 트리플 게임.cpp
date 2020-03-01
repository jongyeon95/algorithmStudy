#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int main(){
	int testcase;
	cin >> testcase;
	for (int t = 1; t <= testcase; ++t)
	{
		vector<int> r;
		vector<int> g;
		vector<int> b;
		string number;
		string rgb;
		cin >> number;
		cin >> rgb;
		for (int i = 0; i < 9; ++i)
		{
			if(rgb[i]=='R')
				r.push_back(number[i]-'0');
			if(rgb[i]=='G')
				g.push_back(number[i]-'0');
			if(rgb[i]=='B')
				b.push_back(number[i]-'0');
		}

		int result=0;

		if(r.size()>=3){
			sort(r.begin(),r.end());
			for (int i = 0; i < r.size()-2; ++i)
			{
				bool check=false;
				if(r[i]==100)
					continue;
				for (int j = i+1; j < r.size()-1; ++j)
				{
					for (int k = j+1; k < r.size(); ++k)
					{
						if(r[i]+1==r[j]&&r[i]+2==r[k]){
							result++;
							r[i]=100;
							r[j]=100;
							r[k]=100;
							check=true;
							break;
						}
					}
					if(check)
						break;
				}
			}
			sort(r.begin(),r.end());
			for (int i = 0; i < r.size()-2; ++i)
			{
				if(r[i]==100)
					break;
				if(r[i]==r[i+1]&&r[i]==r[i+2]){
					result++;
					i+=2;
				}
			}
		}

		if(result<3){
			if(g.size()>=3){
				sort(g.begin(),g.end());
				for (int i = 0; i < g.size()-2; ++i)
				{
					bool check=false;
					if(g[i]==100)
						continue;
					for (int j = i+1; j < g.size()-1; ++j)
					{
						for (int k = j+1; k < g.size(); ++k)
						{
							if(g[i]+1==g[j]&&g[i]+2==g[k]){
								result++;
								g[i]=100;
								g[j]=100;
								g[k]=100;
								check=true;
								break;
							}
						}
						if(check)
							break;
					}
				}
				sort(g.begin(),g.end());
				for (int i = 0; i < g.size()-2; ++i)
				{
					if(g[i]==100)
						break;
					if(g[i]==g[i+1]&&g[i]==g[i+2]){
						result++;
						i+=2;
					}
				}
			}
		}

		if(result<3){
			if(b.size()>=3){
				sort(b.begin(),b.end());
				for (int i = 0; i < b.size()-2; ++i)
				{
					bool check=false;
					if(b[i]==100)
						continue;
					for (int j = i+1; j < b.size()-1; ++j)
					{
						for (int k = j+1; k < b.size(); ++k)
						{
							if(b[i]+1==b[j]&&b[i]+2==b[k]){
								result++;
								b[i]=100;
								b[j]=100;
								b[k]=100;
								check=true;
								break;
							}
						}
						if(check)
							break;
					}
				}
				sort(b.begin(),b.end());
				for (int i = 0; i < b.size()-2; ++i)
				{
					if(b[i]==100)
						break;
					if(b[i]==b[i+1]&&b[i]==b[i+2]){
						result++;
						i+=2;
					}
				}
			}
		}

		printf("#%d ",t);
		if (result>2)
			printf("Win\n");
		else
			printf("Continue\n");

	}
}