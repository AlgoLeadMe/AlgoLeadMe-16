#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> info, int n, int m) {
    const int INF = 1e9;

    vector<int> dp(m, INF);
    dp[0] = 0;

    for (const auto& item : info) {
        int aTrace = item[0];
        int bTrace = item[1];

        vector<int> next(m, INF);

        for (int b = 0; b < m; b++) {

            if (dp[b] == INF) continue;

            if (dp[b] + aTrace < n) {
                next[b] = min(next[b], dp[b] + aTrace);
            }

            if (b + bTrace < m) {
                next[b + bTrace] = min(
                    next[b + bTrace],
                    dp[b]
                );
            }
        }

        dp = next;
    }

    int answer = INF;

    for (int b = 0; b < m; b++) {
        answer = min(answer, dp[b]);
    }

    if (answer == INF) {
        return -1;
    }

    return answer;
}