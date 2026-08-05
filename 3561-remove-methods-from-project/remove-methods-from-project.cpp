class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis,vector<int>& indegree){
        vis[node] = true;
        for(auto& ngbr : adj[node]){
            indegree[ngbr]--;
            if(!vis[ngbr]){
                dfs(ngbr, adj, vis,indegree);
            }
        }
    }
 
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        vector<bool> visbyk(n,false);
        
        for(auto& edge: invocations){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            indegree[v]++;
        }


        dfs(k, adj, visbyk, indegree);

        vector<int> ans;
        bool cannotremove = false;
        
        for(int i=0;i<n;i++){
            if(visbyk[i] && indegree[i] > 0){
                cannotremove = true;
                break;
            }

            if(!visbyk[i]){
                ans.push_back(i);
            }
        }
        
        if(cannotremove){
            vector<int>v;
            for(int i=0;i<n;i++){
                v.push_back(i);
            }
            return v;
        }
        return ans;
    }
};