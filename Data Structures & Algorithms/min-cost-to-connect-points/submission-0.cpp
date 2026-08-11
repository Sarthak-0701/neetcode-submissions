class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        vector<vector<pair<int,int>>> adj(n);
        for(int i = 0 ; i < n-1 ; i++){
            for(int j = i+1 ; j < n ; j++){
                int ux = points[i][0];
                int uy = points[i][1];
                int vx = points[j][0];
                int vy = points[j][1];

                int dist = abs(ux-vx) + abs(uy - vy);

                adj[i].push_back({j , dist});
                adj[j].push_back({i , dist});
            }
        }
        vector<bool> vis(n, false);
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq;

        pq.push({0 , 0});

        int minCost = 0;
        while(!pq.empty()){
            auto it = pq.top();
            int wt = it.first;
            int node = it.second;
            pq.pop();

            if(vis[node])   continue;
            vis[node] = true;
            minCost += wt;
            for (auto& nbr : adj[node]) {
                int v = nbr.first;
                int d = nbr.second;
                if (!vis[v]) {
                    pq.push({d, v});
                }
            }
        }
        return minCost;
    }
};
