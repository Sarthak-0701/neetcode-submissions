class Solution {
public:
    vector<vector<int>> dir = {{1,0} , {-1,0} , {0,1} , {0,-1}};

    void bfs(queue<pair<int,int>>& q , vector<vector<bool>>& visited , vector<vector<int>>& heights){
        int n = heights.size();
        int m = heights[0].size();

        while(!q.empty()){
            auto front = q.front();
            q.pop();
            int r = front.first;
            int c = front.second;
            visited[r][c] = true;

            for(int i = 0 ; i < 4 ; i++){
                int nr = r + dir[i][0];
                int nc = c + dir[i][1];
                if(nr >= 0 && nc >= 0 && nr < n && nc < m && !visited[nr][nc] 
                && heights[nr][nc] >= heights[r][c]){
                    q.push({nr , nc});
                }
            }
        }

    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<bool>> pac( n , vector<bool>(m , false));
        vector<vector<bool>> atl( n , vector<bool>(m , false));

        queue<pair<int,int>> atlantic , pacific;

        for(int r = 0 ; r < n ; r++){
            atlantic.push({r , m-1});
            pacific.push({r , 0});
        }
        for(int c = 0 ; c < m ; c++){
            pacific.push({0 , c});
            atlantic.push({n-1 , c});
        }

        bfs(pacific , pac , heights);
        bfs(atlantic , atl , heights);

        vector<vector<int>> ans;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(atl[i][j] && pac[i][j])    ans.push_back({i , j});
            }
        }
        return ans;
    }
};
