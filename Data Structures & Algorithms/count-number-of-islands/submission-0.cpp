class Solution {
public:

    void bfs(vector<vector<char>>& grid , int i , int j){
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        q.push({i , j});
        
        vector<int> dr = {0 , 0 , -1 , 1};
        vector<int> dc = {-1 , 1 , 0 , 0};
        
        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            for(int i = 0 ; i < 4 ; i++){
                int nr = x + dr[i];
                int nc = y + dc[i];
                if(nr >= 0 && nc >= 0 && nr < n && nc < m && grid[nr][nc] == '1'){
                    q.push({nr , nc});
                    grid[nr][nc] = '0';
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int count = 0;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == '1'){
                    grid[i][j] = '0';
                    bfs(grid , i , j);
                    count++;
                }
            }
        }
        return count;
    }
};
