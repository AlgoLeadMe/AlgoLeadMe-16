#include <bits/stdc++.h>

using namespace std;

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    
    vector<vector<pair<int, int>>> graph(N+1);
    
    for(int i = 0; i < road.size(); i++){
        int a = road[i][0];
        int b = road[i][1];
        int cost = road[i][2];
        
        graph[a].push_back({b, cost});
        graph[b].push_back({a, cost});
    }
    
    const int INF = INT_MAX;
    vector<int> dist(N+1, INF);
    
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    dist[1] = 0;
    pq.push({0,1});
    
    while(!pq.empty()) {
        int curDist = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        
        if(curDist > dist[cur]) continue;
        
        for(int i = 0; i < graph[cur].size(); i++){
            int next = graph[cur][i].first;
            int cost = graph[cur][i].second;
            
            if(dist[next] > curDist + cost) {
                dist[next] = curDist + cost;
                pq.push({dist[next],next});
            }
        }
        
    }
    
    for(int i = 0; i <= N; i++){
        if(dist[i] <= K){
            answer++;
        }
    }
     
    return answer;
}