#include <string>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(const auto& c : scoville)
    {
        pq.push(c);
    }
    
    while(pq.top() < K && pq.size() >= 2)
    {
        int s1 = pq.top();
        pq.pop();
        int s2 = pq.top();
        pq.pop();
        
        int s = s1 + (s2 * 2);
        pq.push(s);
        answer++;
    }
    
    return (pq.top() >= K) ? answer : -1;
}