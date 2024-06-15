//*****https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1*****


//T.C: O(n) + O(n + 2*E);
//S.C: 2*O(n);
class Solution {
  private: 
    bool dfs(int node, int parent, int vis[], vector<int> adj[]) {
        vis[node] = 1;

        for(auto adjacentNode: adj[node]){
            if(!vis[adjacentNode]) {
                if(dfs(adjacentNode, node, vis, adj) == true) 
                    return true; 
            }
            else if(adjacentNode != parent) return true; 
        }

        return false; 
    }
  public:
    bool isCycle(int V, vector<int> adj[]) {
       int vis[V] = {0};

       for(int i = 0;i<V;i++) {
           if(!vis[i]) {
               if(dfs(i, -1, vis, adj) == true) return true; 
           }
       }

       return false; 
    }
};


/*CONCEPT OF CHECKING IF THERE ARE MORE THAN TWO PARENT NODES FOR 
  ANY NODE TO DETECT A CYCLE: */

/*We can also solve it without storing the parent, A particular 
  node can be marked visited only by its parent so when we reach 
  a node and traverse all its adjacent node and find more than 
  one visited ,that shows this node has more than one parent or 
  we can simply say this particular node is also getting visited 
  from another direction and in that case we can say there is 
  cycle present. */
//T.C: O(n) + O(n + 2*E);
//S.C: 2*O(n);
class Solution {
  private: 
    bool dfs(int node, int vis[], vector<int> adj[]) {
        vis[node] = 1;
        int cnt = 0;
        
        for(auto adjacentNode: adj[node]){
            if(!vis[adjacentNode]) {
                if(dfs(adjacentNode, vis, adj) == true) 
                    return true; 
            }
            else{
                cnt++;
            }
            if(cnt > 1) return true;
        }

        return false; 
    }
  public:
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V] = {0};

        for(int i = 0;i<V;i++) {
            if(!vis[i]) {
               if(dfs(i, vis, adj) == true) return true; 
            }
        }

        return false; 
    }
};