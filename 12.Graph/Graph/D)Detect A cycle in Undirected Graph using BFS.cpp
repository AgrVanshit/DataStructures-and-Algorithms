//*****https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1*****


//T.C: O(n) + O(2 * E);
//S.C: 2*O(n);
class Solution {
  private:
    bool detect(int src, vector<int> adj[], int vis[]){
        vis[src] = 1;
        queue<pair<int, int>> q;
        q.push({src, -1});
        
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(auto adjNode : adj[node]){
                if(!vis[adjNode]){
                    vis[adjNode] = 1;
                    q.push({adjNode, node});
                }
                else if(parent != adjNode){
                    return true;
                }
            }
        }

        return false;
    }
  public:
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V] = {0};

        for(int i = 0; i < V; i++){
            if(!vis[i]){
                if(detect(i, adj, vis)) return true;
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
//T.C: O(n) + O(2 * E);
//S.C: 2*O(n);
class Solution {
  public:
    bool bfs(int node,vector<int> &vis, vector<int> adj[]){
        queue<int> q;
        q.push(node);
        vis[node] = 1;

       while(!q.empty()){
          int frnt = q.front();
          q.pop();

          int cnt = 0;

          for(auto it:adj[frnt]){
              if(!vis[it]){
                  q.push(it);
                  vis[it] = 1;
              }
              else {
                  cnt++;
              }
          }

          if(cnt > 1) return true;
       }

       return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V,0);

        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(bfs(i,vis,adj)) return true;
            }
        }

        return false;
    }
};