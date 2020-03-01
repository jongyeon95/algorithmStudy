#include <iostream>
#include <string>

using namespace std;

int main(){
	string input;
	char alphabet[26];
	int result[26];
	int j=0;

    //유니코드를 사용하여 알파벳 넣기
    //result[]를 -1로 초기화 
	for (int i = 97; i <= 122; i++)
	{
		alphabet[j]=i; 
		result[j]=-1;
		j++;
	}


	cin >> input;
	for (int i = 0; i < input.size(); i++)
	{
		for (int j = 0; j < 26; j++)
		{
			if(alphabet[j]==input[i]){
				if(result[j]==-1){
					result[j]=i;
					continue;
				}
			}
		}
	}

	for (int i = 0; i < 26; i++)
	{
		cout<<result[i]<<" ";
	}



	

}