class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> indegree(n+1 , 0);
        vector<vector<int>> adj(n+1);
        for(auto&edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            indegree[u]++;
            indegree[v]++;
        }

        queue<int> q;
        for(int i = 0 ; i <= n ; i++){
            if(indegree[i] == 1)    q.push(i);
        }

        while(!q.empty()){
            int front = q.front();
            q.pop();
            indegree[front]--;
            for(int nbr : adj[front]){
                indegree[nbr]--;
                if(indegree[nbr] == 1)  q.push(nbr);
            }
        }

        for(int i = n-1 ; i >= 0 ; i--){
            int u = edges[i][0] , v = edges[i][1];
            if(indegree[u] == 2 && indegree[v]) return {u,v};
        }
        return {};
    }
};
