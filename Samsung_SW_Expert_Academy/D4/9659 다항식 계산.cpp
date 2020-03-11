#include <iostream>
#include <cstring>
using namespace std;
long long n,m;
long long arrFx[51];
long long arrN[51][3];
long long arrM[51];

void resetArrFx(int x){
	for (int i = 0; i < 51; ++i)
	{
		arrFx[i]=-1;
	}
	arrFx[0]=1;
	arrFx[1]=x;
}

long long solve(int x , int nFlag){

	if(arrFx[nFlag]!=-1)
		return arrFx[nFlag];
	if(arrN[nFlag][0]==1){
		if (arrFx[arrN[nFlag][1]]==-1)
		{
			arrFx[arrN[nFlag][1]]=solve(x,arrN[nFlag][1]);
		}
		if(arrFx[arrN[nFlag][2]]==-1){
			arrFx[arrN[nFlag][2]]=solve(x,arrN[nFlag][2]);
		}

		arrFx[nFlag]=(arrFx[arrN[nFlag][1]]+arrFx[arrN[nFlag][2]])%998244353;
	}
	else if(arrN[nFlag][0]==2){
		if(arrFx[arrN[nFlag][2]]==-1){
			arrFx[arrN[nFlag][2]]=solve(x,arrN[nFlag][2]);
		}

		arrFx[nFlag]=(arrN[nFlag][1]*arrFx[arrN[nFlag][2]])%998244353;
	}

	else{
		if (arrFx[arrN[nFlag][1]]==-1)
		{
			arrFx[arrN[nFlag][1]]=solve(x,arrN[nFlag][1]);
		}
		if(arrFx[arrN[nFlag][2]]==-1){
			arrFx[arrN[nFlag][2]]=solve(x,arrN[nFlag][2]);
		}

		arrFx[nFlag]=(arrFx[arrN[nFlag][1]]*arrFx[arrN[nFlag][2]])%998244353;

	}

	return arrFx[nFlag];

}
	

int main(){
	cin.tie(0);
	cout.sync_with_stdio(false);
	int testcase;
	cin >> testcase;
	for (int t = 1; t <= testcase; ++t)
	{
		cin >> n;
		for (int i = 2; i <= n; ++i)
		{
			cin >> arrN[i][0] >> arrN[i][1] >> arrN[i][2];
		}
		cin >> m;
		for (int i = 1; i <= m; ++i)
		{
			cin >> arrM[i];
		}

		cout << "#" <<t<<" ";

		for (int i = 1; i <= m; ++i)
		{
			resetArrFx(arrM[i]);
			cout << solve(arrM[i],n) <<" ";
		}
		cout << "\n";

	}
}