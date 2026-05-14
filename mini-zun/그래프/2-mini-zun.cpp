#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    int n = maps.size();
    int m  = maps[0].size();
    
    vector<vector<bool>> visited(n,vector<bool>(m, false));
    
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(maps[i][j] != 'X' && !visited[i][j]){
                queue<pair<int,int>> q;
                q.push({i,j});
                visited[i][j] = true;
                
                int sum = 0;
                
                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    
                    sum += maps[x][y] - '0';
                    
                    for(int dir = 0; dir < 4; dir++){
                        int nx = x + dx[dir];
                        int ny = y + dy[dir];
                        
                        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if(visited[nx][ny]) continue;
                        if(maps[nx][ny] == 'X') continue;
                        
                        visited[nx][ny] = true;
                        q.push({nx,ny});
                    }
                }
                answer.push_back(sum);
            }
        }
    }
    sort(answer.begin(),answer.end());
    
    if(answer.empty()){
        answer.push_back(-1);
    }
    return answer;
}