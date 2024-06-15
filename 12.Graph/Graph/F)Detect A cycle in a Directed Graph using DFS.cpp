//*****https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1*****


//T.C: O(n) + O(E);
//S.C: 3*O(n);
class Solution {
  private:
    bool dfs(int node, int V, int vis[], int pathVis[], vector<int> adj[]){
        vis[node] = 1;
        pathVis[node] = 1;
        
        for(auto it : adj[node]){
            if(!vis[it]){
                if(dfs(it, V, vis, pathVis, adj) == true) return true ;
            }
            else if(pathVis[it]){
                return true;
            }
        }
        
        pathVis[node] = 0;
        return false;
    }
  public:
    bool isCyclic(int V, vector<int> adj[]) {
        int vis[V] = {0};
        int pathVis[V] = {0};
        
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                if(dfs(i, V, vis, pathVis, adj) == true) return true;
            }
        }

        return false;
    }
};