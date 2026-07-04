#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool bIsMul3Bigger(const string& a, const string& b)
{
    string aa = "";
    string bb = "";
    for(int i = 0; i < 3; ++i)
    {
        aa += a;
        bb += b;
    }
    return aa > bb;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> sn;
    
    for(const auto& n : numbers)
    {
        sn.push_back(to_string(n));
    }
    
    sort(sn.begin(), sn.end(), bIsMul3Bigger);
    
    for(const auto& c : sn)
    {
        answer += c;
    }
    
    for(const auto& c : answer)
    {
        if(c != '0')
        {
            return answer;
        }
    }
    return "0";
}