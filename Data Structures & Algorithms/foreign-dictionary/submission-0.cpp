class Solution {
public:

    string topoSort(const vector<unordered_set<int>> adj, vector<int>& indegree, 
    const vector<bool>& present){
        
        int totalNodes = 0;
        queue<int> q;

        for(int i = 0 ; i < 26 ; i++){
            if(present[i]){
                totalNodes++;
                if(indegree[i] == 0){
                    q.push(i);
                }
            }
        }

        string ans = "";

        while(!q.empty()){
            int front = q.front();
            q.pop();
            ans += char(front+'a');

            for(int nbr : adj[front]){
                indegree[nbr]--;
                if(indegree[nbr] == 0){
                    q.push(nbr);
                }
            }
        }

        if(ans.size() != totalNodes){
            return "";
        }

        return ans;

    }

    string foreignDictionary(vector<string>& words) {
        vector<unordered_set<int>> adj(26);
        vector<int> indegree(26 , 0);
        vector<bool> present(26, false);

        for(const string& w : words){
            for(char ch : w){
                present[ch - 'a'] = true;
            }
        }

        for(int i = 0 ; i < words.size()-1 ; i++){
            string s1 = words[i];
            string s2 = words[i+1];
            int len = min(s1.length() , s2.length());
            int idx = 0;

            while(idx < len && s1[idx] == s2[idx]){
               idx++;
            }
            if(idx == len){
                if(s1.length() > s2.length()){
                return "";
                }
            }
            else{
                int u = s1[idx] - 'a';
                int v = s2[idx] - 'a';
                if(!adj[u].count(v)){
                    adj[u].insert(v);
                    indegree[v]++;
                }
            }
        }
        string ans = topoSort(adj, indegree, present);
        return ans;
    }
};
