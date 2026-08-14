class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int , int>> q;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ;  j < m ; j++){
                if(grid[i][j] == 0){
                    q.push({i , j});
                }
            }
        }
        int dr[] = {0 , 0 , -1 ,1 };
        int dc[] = {-1 , 1 , 0 ,0 };
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int r = it.first;
            int c = it.second;
            int d = grid[r][c];
            for(int i = 0 ; i < 4 ; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] != -1 && grid[nr][nc] != 0){
                    if(grid[nr][nc] > d + 1){
                        q.push({nr , nc});
                        grid[nr][nc] = d+1;
                    }
                }
            }
        }
        return;
    }
};
