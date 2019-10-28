#include <iostream>
#include <string>
using namespace std;
int cnt=0;
void pali(string temp, int start, int last){
    int j=0;
    bool a=false;
    for(int i=start; i<=(last-start)/2+start; i++){
            if(last-start<2){break;}
            if(temp[i]==temp[last-j]){
                a=true;
            }
            else{
                a=false;
                break;
            }
            j++;

    }
    if(a){
        for(int i=start; i<=last; i++){
            cout<<temp[i];
        }
        cout << " ";
        cnt++;
    }

}



int main()
{
   int TestCase;
   cin >> TestCase;
   for(int i=0; i<TestCase; i++){
        cnt=0;
        string s;
        cin >> s;
        cout << "#" << TestCase+1<<" ";
        for(int k=0; k<s.length();k++){
            for(int j=s.length()-1; j>k; j--){
                pali(s,k,j);
            }
        }
        if(cnt==0){
            cout << " 0" << endl;
        }
        else{
            cout << " ," << cnt << endl;
        }
   }
   return 0;
}
