class Solution {
public:

    void bfs(vector<vector<int>>& grid , int r , int c, int& maxi){
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        q.push({r , c});
        grid[r][c] = 0;
        int size = 0;

        int dr[] = {0 , 0 , -1 , 1};
        int dc[] = {1 , -1 , 0 , 0};

        while(!q.empty()){
            auto [x , y] = q.front();
            q.pop();
            size++;

            for(int i =0 ; i< 4 ; i++){
                int nr = x + dr[i];
                int nc = y + dc[i];
                if(nr >= 0 && nc >= 0 && nr < n && nc < m && grid[nr][nc] == 1){
                    q.push({nr,nc});
                    grid[nr][nc] = 0;
                }
            }
        }

        maxi = max(maxi , size);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxi = 0;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1){
                    bfs(grid , i , j , maxi);
                }
            }
        }        
        return maxi;
    }
};
