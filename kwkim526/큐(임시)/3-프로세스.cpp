#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> q;
    for(int i = 0; i < priorities.size(); ++i)
    {
        q.push(make_pair(priorities[i], i));
    }
    sort(priorities.rbegin(), priorities.rend());
    int priority = 0;
    while(!q.empty())
    {
        auto a = q.front();
        q.pop();
        if(a.first == priorities[priority])
        {
            ++answer;
            if(a.second == location)
            {
                return answer;
            }
            ++priority;
        }
        else
        {
            q.push(a);
        }
    }
    return answer;
}