#include <iostream>
#include <string>
using namespace std;
int main(){
	int testcase;
	cin >> testcase;
	for (int t = 1; t <= testcase; ++t)
	{
		int cH,cM,cS;
		int pH,pM,pS;
		int rH,rM,rS;
		rH=0;
		rM=0;
		rS=0;
		string currentTime;
		string promissTime;
		cin >> currentTime;
		cin >> promissTime;
		cH=((int)currentTime[0]-'0')*10+(int)currentTime[1]-'0';
		cM=((int)currentTime[3]-'0')*10+(int)currentTime[4]-'0';
		cS=((int)currentTime[6]-'0')*10+(int)currentTime[7]-'0';
		pH=((int)promissTime[0]-'0')*10+(int)promissTime[1]-'0';				
		pM=((int)promissTime[3]-'0')*10+(int)promissTime[4]-'0';
		pS=((int)promissTime[6]-'0')*10+(int)promissTime[7]-'0';
		if(pS<cS){
			rS+=60-cS+pS;
			rM-=1;
		}
		else 
			rS+=pS-cS;
		if(pM<cM){
			rM+=60-cM+pM;
			rH-=1;
		}
		else 
			rM+=pM-cM;
		if(pH<cH)
			rH+=24-cH+pH;
		else 
			rH+=pH-cH;

		if(rH<0)
			rH+=24;
		cout << "#" << t<<" ";
		if(rH<10)
			cout<<"0";
		cout<<rH<<":";
		if(rM<10)
			cout<<"0";
		cout<<rM<<":";
		if(rS<10)
			cout<<"0";
		cout<<rS<<"\n";

	}

}