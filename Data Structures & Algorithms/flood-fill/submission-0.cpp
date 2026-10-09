class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> visited(n , vector<int>(m , 0));
        visited[sr][sc] = 1;
        int original = image[sr][sc];
        q.push({sr,sc});

        vector<int> dr = {0 , 0 , 1 , -1};
        vector<int> dc = {1 , -1 , 0 , 0};
        while(!q.empty()){
            auto [r , c] = q.front();
            image[r][c] = color;
            q.pop();
            for(int i = 0 ; i < 4 ; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr >= 0 && nc >= 0 && nr < n && nc < m 
                && image[nr][nc] == original && !visited[nr][nc]){
                    visited[nr][nc] = 1;
                    q.push({nr , nc});
                }
            }
        }
        return image;
    }
};