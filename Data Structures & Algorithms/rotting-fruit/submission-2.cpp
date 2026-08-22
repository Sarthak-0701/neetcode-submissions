class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        int freshoranges = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1){
                    freshoranges++;
                }
                else if(grid[i][j] == 2){
                    q.push({i , j});
                }
            }
        } 

        if(freshoranges == 0){
            return 0;
        }

        // if(q.size() == 0){
        //     return -1;
        // }

        int dr[4] = {0 , 0 , -1 , 1};
        int dc[4] = {-1 , 1 , 0 , 0};

        int time = -1;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto front = q.front();
                q.pop();
                int x = front.first;
                int y = front.second;

                for(int i = 0 ; i < 4 ; i++){
                    int nr = x + dr[i];
                    int nc = y + dc[i];

                    if(nr < n && nr >= 0 && nc < m && nc >= 0 && grid[nr][nc] == 1){
                        q.push({nr , nc});
                        grid[nr][nc] = 2;
                        freshoranges--;
                    }
                }
            }
            time++;
        }
        if(freshoranges > 0){
            return -1;
        }
        return time;
    }
};
