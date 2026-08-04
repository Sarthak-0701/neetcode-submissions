class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        vector<int> indegree(numCourses , 0);
        for(int i = 0 ; i < prerequisites.size() ; i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adjList[v].push_back(u);
            indegree[u]++;
        }

        queue<int> q;
        int count = 0;
        for(int i = 0 ; i < numCourses ; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            count++;
            ans.push_back(front);
            for(int nbr : adjList[front]){
                indegree[nbr]--;

                if(indegree[nbr] == 0)
                    q.push(nbr);
                
            }
        }
        if(count == numCourses)
            return ans;

        return {};
    }
};
