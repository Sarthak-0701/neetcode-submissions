class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(int i = 0 ; i < times.size() ; i++){
            int u = times[i][0]-1;
            int v = times[i][1]-1;
            int w = times[i][2];
            adj[u].push_back({v, w});
        }

        vector<int> dist(n , -1);
        dist[k-1] = 0;
        priority_queue<pair<int, int> , vector<pair<int,int>> , greater<pair<int,int>> > pq;
        pq.push({0 , k-1});

        while(!pq.empty()){
            auto front = pq.top();
            pq.pop();
            int node = front.second;
            int d = front.first;

            for(auto nbr : adj[node]){
                int v = nbr.first;
                int w = nbr.second;
                if(dist[v] == -1 || w + d < dist[v]){
                    dist[v] = w + d;
                    pq.push({dist[v] , v});
                }
            }

        }
        int time = 0;
        for(int i = 0 ; i < n ; i++){
            if(dist[i] == -1)   return -1;
            time = max(time , dist[i]);
        }
        return time;
    }
};
