#include<string>
#include<iostream>
using namespace std;
 
int main()
{
    int testcase;
    int T;
    int max=0,min=0,result=0;
     
    string input;
     
    cin>>T;
   
    for(testcase = 1; testcase <= T; ++testcase)
    {
    	max=0;
    	min=0;
    	result=0;
      for(int i=0;i<10;i++)
      {
      		result=0;
            cin>>input;
            for(int j=0;j<input.size();j++)
            {
               // cout<<input<<endl;
                result+=input[j]-48;
            }
          if(i==0)
          {
              max=result;
              min=result;
              continue;
          }
           
          if(result>max)
              max=result;
          if(result<min)
              min=result;
      }
        printf("#%d %d %d\n",testcase,max,min);
    }
    return 0;
}