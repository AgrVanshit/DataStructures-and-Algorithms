//https://www.geeksforgeeks.org/problems/number-of-provinces/1


class Solution {
  public:
    void dfs(int node, vector<int> adjs[], vector<int>& vis){
        vis[node] = 1;
        
        for(auto it : adjs[node]){
            if(!vis[it]){
                dfs(it, adjs, vis);
            }
        }  
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int> vis(V + 1, 0);
        vector<int> adjs[V + 1];
        
        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){
                if(adj[i][j] == 1 && i != j){
                    adjs[i + 1].push_back(j + 1);
                    adjs[j + 1].push_back(i + 1);
                }
            }
        }
        
        int cnt = 0;
        
        for(int i = 1; i <= V; i++){
            if(!vis[i]){
                cnt++;
                dfs(i, adjs, vis);
            }
        }
        
        return cnt;
    }
};