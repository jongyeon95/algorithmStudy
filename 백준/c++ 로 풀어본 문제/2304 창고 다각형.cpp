#include <iostream>
using namespace std;
int arr[1001];
int main(){
	int n;
	cin >> n;
	int minIndex=1001;
	int maxIndex=0;
	int LongIndex=0;
	int maxHeight=0;
	for (int i = 0; i < n; ++i)
	{
		int  a , b;
		cin >> a >> b;
		if(b>maxHeight){
			maxHeight=b;
			LongIndex=a;
		}
		if(a>maxIndex)
			maxIndex=a;
		if(a<minIndex)
			minIndex=a;
		arr[a]=b;
	}
	int heigt=arr[minIndex];
	int tempIndex=minIndex;
	for (int i = minIndex; i <= LongIndex; ++i)
	{
		if(arr[i]>=heigt){
			for (int j = tempIndex; j < i; ++j)
			{
				arr[j]=heigt;
			}
			heigt=arr[i];
			tempIndex=i;
		}
		
	}

	heigt=arr[maxIndex];
	tempIndex=maxIndex;
	for (int i = maxIndex; i >= LongIndex; i--)
	{
		if(arr[i]>=heigt){
			for (int j = tempIndex; j > i; j--)
			{
				arr[j]=heigt;
			}
			heigt=arr[i];
			tempIndex=i;
		}
	}

	int result=0;
	for (int i = minIndex; i <= maxIndex; ++i)
	{
		result+=arr[i];
	}
	cout<<result;

}