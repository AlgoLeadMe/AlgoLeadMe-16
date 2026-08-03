#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> bridge_status;
    int cur_weights = 0;
    int idx = 0;
    
    for(int i = 0; i < bridge_length; i++){
        bridge_status.push(0);
    }
    
    while(idx < truck_weights.size()){
        answer++;
        cur_weights -= bridge_status.front();
        bridge_status.pop();
        if(cur_weights + truck_weights[idx] <= weight){
            bridge_status.push(truck_weights[idx]);
            cur_weights += truck_weights[idx];
            idx++;
        } else {
            bridge_status.push(0);
        }
    }
    answer += bridge_length;
    return answer;
}