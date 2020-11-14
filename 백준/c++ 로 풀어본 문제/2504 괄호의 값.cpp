#include <iostream>
#include <stack>
#include <string>
#include <cmath>
using namespace std;


string input;
stack<char> s;

int main(void)
{

        ios_base::sync_with_stdio(0);
        cin.tie(0); 
        cin >> input;

        long long result = 0;
        int temp = 1;
        bool impossible = false;

        for (int i = 0; i < input.size(); i++)
        {
                 if (input[i] == '(')
                 {
                         temp *= 2;
                         s.push('(');
                 }
                 else if (input[i] == '[')
                 {
                         temp *= 3;
                         s.push('[');
                 }
                 else if (input[i] == ')' && (s.empty() || s.top() != '('))
                 {
                         impossible = true;
                         break;
                 }

                 else if (input[i] == ']' && (s.empty() || s.top() != '['))
                 {
                         impossible = true;
                         break;
                 }
                 else if (input[i] == ')')
                 {
                         if (input[i - 1] == '(')
                                 result += temp;
                         s.pop();
                         temp /= 2;
                 }
                 else if (input[i] == ']')
                 {

                         if (input[i - 1] == '[')
                                 result += temp;
                         s.pop();
                         temp /= 3;
                 }

        }

 
        if (impossible || !s.empty())
                 cout << 0 << "\n";
        else
                 cout << result << "\n";
        return 0;

}



