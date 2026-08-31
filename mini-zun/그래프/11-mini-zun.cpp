#include <queue>
#include <string>
#include <vector>

using namespace std;

vector<int> spread(int type, vector<vector<pair<int, int>>> &graph, vector<bool> &infected) {
    vector<int> changed;
    queue<int> q;

    for (int i = 1; i < infected.size(); i++) {
        if (infected[i]) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (const auto &edge : graph[cur]) {
            int next = edge.first;
            int piptype = edge.second;

            if (piptype == type && !infected[next]) {
                infected[next] = true;
                changed.push_back(next);
                q.push(next);
            }
        }
    }

    return changed;
} // 감염된 것들 큐에 다 넣기

void dfs(int depth, int k, vector<vector<pair<int, int>>> &graph, vector<bool> &infected,
         int &answer) {
    int count = 0;

    for (int i = 0; i <= infected.size(); i++) {
        if (infected[i]) {
            count++;
        }
    }
    answer = max(answer, count);

    if (depth == k) {
        return;
    }

    for (int type = 1; type <= 3; type++) {
        vector<int> changed = spread(type, graph, infected);

        dfs(depth + 1, k, graph, infected, answer);

        for(int node : changed){
            infected[node] = false;
        }
    }
}

int solution(int n, int infection, vector<vector<int>> edges, int k) {
    int answer = 0;
    vector<vector<pair<int, int>>> graph(n + 1);
    vector<bool> infected(n + 1, false);

    for (const auto &edge : edges) {
        int x = edge[0];
        int y = edge[1];
        int type = edge[2];

        graph[x].push_back({y, type});
        graph[y].push_back({x, type});
    } // 트리 구현

    infected[infection] = true; // 초기 감염상태 지정

    dfs(0, k, graph, infected, answer);
    return answer;
}