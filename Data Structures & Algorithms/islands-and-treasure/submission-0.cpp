class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int> , int>> q;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ;  j < m ; j++){
                if(grid[i][j] == 0){
                    q.push({{i , j} , 0});
                }
            }
        }
        int dr[] = {0 , 0 , -1 ,1 };
        int dc[] = {-1 , 1 , 0 ,0 };
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int r = it.first.first;
            int c = it.first.second;
            int d = it.second;
            for(int i = 0 ; i < 4 ; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] != -1 && grid[nr][nc] != 0){
                    if(grid[nr][nc] > d + 1){
                        q.push({{nr , nc} , d+1});
                        grid[nr][nc] = d+1;
                    }
                }
            }
        }
        return;
    }
};
