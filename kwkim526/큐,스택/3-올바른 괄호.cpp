#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<bool> isOpened;
    
    for(const auto& c : s)
    {
        if(c == '(')
        {
            isOpened.push(true);
        }
        else
        {
            if(isOpened.empty())
            {
                return false;
            }
            else
            {
                isOpened.pop();
            }
        }
    }
    
    return isOpened.empty();
}