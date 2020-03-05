#include <iostream>
using namespace std;
int timeTable[2001];
int letter[100];

void initArr(){
	for (int i = 0 ; i <2001; ++i)
	{
		if(i<100)
			letter[i]=0;
		timeTable[i]=0;
	}
}

int main(){
	cin.tie(0);
	cout.sync_with_stdio(false);
	int testcase;
	cin >> testcase;
	for (int t = 1; t <= testcase; t++)
	{
		initArr();
		int N,A,B;
		cin >> N >> A >> B;
		for (int i = 0; i < N; ++i)
		{
			int temp;
			cin >> temp;
			letter[i]=temp;
			timeTable[temp]++;
		}
		
		int numFlag=0;
		int letterflag=0;
		cout<<"#"<<t<<" ";
		for (int i = 1; i < 2001; ++i)
		{

			if(timeTable[i]!=0){
				numFlag++;
				if(numFlag==A){
					int length=numFlag/2+numFlag%2;
					for (int j = letterflag; j < letterflag+length; ++j)
					{
						cout << i << " ";
						numFlag--;
					}
					letterflag+=length;
				}
			}
			if(numFlag!=0){
				if(i-letter[letterflag]==B)
				{
					int length=numFlag/2+numFlag%2;
					for (int j = letterflag; j < letterflag+length; ++j)
					{
						cout << i << " ";
						numFlag--;
					}
					letterflag+=length;
				}
			}
			if(letterflag>=N)
				break;
		}
		
		cout << "\n";
	}
}