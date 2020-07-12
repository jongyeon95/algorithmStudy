#include<cstdio>
#include<string>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
    string result[]={"NA","MMYY","YYMM","AMBIGUOUS"};
	int T;
	scanf("%d",&T);
	for(test_case = 1; test_case <= T; ++test_case)
	{
        char c[4];
        int resultNum=0;
        scanf("%s",c);
        
        int frontNum=10*(c[0]-'0')+c[1]-'0'; //앞 두자리
       	int backNum=10*(c[2]-'0')+c[3]-'0'; //뒤 두자리
       
        if(frontNum<13&&frontNum>0) resultNum+=1;
        if(backNum<13&&backNum>0) resultNum+=2;
       
        printf("#%d %s\n",test_case,result[resultNum].c_str());
  
	}
	return 0;