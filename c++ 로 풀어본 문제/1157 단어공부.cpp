#include <iostream>
#include <string>
#include <cstring>
using namespace std;


int main(){
	string s;
	cin >> s;
	int Alphabet[26];
	int max=-1;
	int maxAlphabet=0;
	char result;
	memset(Alphabet,0,sizeof(Alphabet));
	for (int i = 0; i < s.size(); i++)
	{
		if(s[i]>=97)
			s[i]-=97;
		else
			s[i]-=65;
		Alphabet[s[i]]++;
	}
	for(int i=0; i<26; i++){
		if(max<Alphabet[i]){
			max=Alphabet[i];
			maxAlphabet=i+65;
		}
	}
	int checkCnt=0;
	for(int i=0; i<26; i++){
		if(max==Alphabet[i])
			checkCnt++;
	}
	result=maxAlphabet;
	if(checkCnt==1){
		cout << result;
	}
	else 
		cout << '?';

}