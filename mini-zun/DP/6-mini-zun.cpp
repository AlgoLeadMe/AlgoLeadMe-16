#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    int road[101][101] = {0,};
    road[1][1] = 1;
    
    for(int i = 0; i < puddles.size(); i++){
        int x = puddles[i][0];
        int y = puddles[i][1];
        
        road[y][x] = -1;
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int up = 0;
            int left = 0;
            if(i == 1 && j == 1) continue;
            if(road[i][j] == -1) continue;
            
            if(road[i-1][j] != -1){
                up = road[i-1][j];
            }
            if(road[i][j-1] != -1){
                left = road[i][j-1];
            }
            
            road[i][j] = (up + left) % 1000000007;
        }
    }
    answer = road[n][m];
    return answer;
}