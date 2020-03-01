#include <iostream>
#include <deque>
using namespace std;
deque<int> dq;
int result=0;

void Lshift(int num){
	for (int i = 0; i < num; i++)
	{
		dq.push_back(dq.front());
		dq.pop_front();
	}
	result+=num;
	dq.pop_front();
}
void Rshift(int num){
	for (int i = 0; i < num; i++)
	{
		dq.push_front(dq.back());
		dq.pop_back();
	}
	result+=num;
	dq.pop_front();
}

int FindLocation(int num){
	for (int i = 0; i < dq.size(); ++i)
	{
		if(dq[i]==num)
			return i;
	}
}



int main(){
	int size,popnum;
	
	

	cin >> size >> popnum;
	for (int i = 1; i <= size; i++)
	{
		dq.push_back(i);
	}

	for (int i = 0; i < popnum; ++i)
	{
		int temp;
		int locate;
		cin >> temp;
		locate=FindLocation(temp);
		if(locate<=dq.size()-locate)
			Lshift(locate);
		else
			Rshift(dq.size()-locate);

		
	}
	if(result==0)
		cout<<0;
	else
		cout<< result;

}