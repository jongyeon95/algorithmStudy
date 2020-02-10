#include<iostream>
#include<stack>
#include<vector>
using namespace std;
 
int main() {
    int size;
    int flagNum=1;
    int flag=0;
    bool IsTrue=true;
    stack<int> s;
    vector<char> output;
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; ++i)
    {
        cin >> arr[i];
    }

   
    while(1){
        if(flag==size||flagNum>size+1){
            break;
        }
        else if(s.size()==0){
            output.push_back('+');
            s.push(flagNum);
            flagNum++;
        }
        else if(s.top()==arr[flag]){
            s.pop();
            output.push_back('-');
            flag++;
        }
        else if(s.top()>arr[flag]){
            IsTrue=false;
            break;
        }
        else{
            output.push_back('+');
            s.push(flagNum);
            flagNum++;
        }
    }
    if(IsTrue){
        for (int i = 0; i < output.size(); ++i)
        {
            printf("%c\n",output[i]);
        }
    }
    else
        cout << "NO";


}
