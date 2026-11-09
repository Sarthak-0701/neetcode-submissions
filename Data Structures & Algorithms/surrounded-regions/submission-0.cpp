class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        queue<pair<int,int>> q;

        for(int i = 0 ; i < n ; i++){
            if(board[i][0] == 'O'){
                q.push({i,0});
            }
            if(board[i][m-1] == 'O'){
                q.push({i,m-1});
            }
        }
        for(int j = 0 ; j < m ; j++){
            if(board[0][j] == 'O'){
                q.push({0,j});
            }
            if(board[n-1][j] == 'O'){
                q.push({n-1,j});
            }
        }

        int dr[] = {0 , 0 , -1 , 1};
        int dc[] = {-1 , 1 , 0 , 0};

        while(!q.empty()){
            auto [r , c] = q.front();
            board[r][c] = 'Y';
            q.pop();

            for(int i = 0 ; i < 4 ; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr >= 0 && nc >= 0 && nr < n-1 && nc < m-1 
                && board[nr][nc] == 'O'){
                    q.push({nr , nc});
                }
            }
        }

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                board[i][j] = (board[i][j] == 'Y') ? 'O' : 'X';
            }
        }
        return;
    }
};
