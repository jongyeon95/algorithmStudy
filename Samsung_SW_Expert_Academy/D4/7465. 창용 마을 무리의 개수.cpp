#include<vector>
#include<iostream>
#include<cstring>

using namespace std;
vector<vector<int>> v;
bool check[101];


void dfs(int flag){
	for(int i=0; i<v[flag].size(); i++){
    	int temp=v[flag][i];
        if(!check[temp]){
        	check[temp]=true;
            dfs(temp);
        }
    }
}


int main(int argc, char** argv)
{
    cin.tie(0);
    cout.tie(0);
    cout.sync_with_stdio(false);
	int test_case;
	int T;
	
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int n,m,cnt;
        v.clear();
        cnt=0;
        memset(check,false,sizeof(check));
        cin >> n >> m;
        v.resize(n);
        
        while(m--){
        	int start,end;
            cin >> start >> end;
            start--;
            end--;
            v[start].push_back(end);
            v[end].push_back(start);
        }
        for(int i=0; i<n; i++){
        	if(!check[i]){
            	cnt++;
                check[i]=true;
                dfs(i);
            }
        }
        cout<<"#"<<test_case<<" "<<cnt<<"\n";

	}
	return 0;
}