//*****https://www.geeksforgeeks.org/problems/topological-sort/1*****
//TOPOLOGICAL SORTING IS POSSIBLE IN DIRECTED ACYCLIC GRAPHS ONLY:


//T.C: O(n) + O(E);
//S.C: 3*O(n);
class Solution
{
    private:
    void dfs(int node, vector<int>& vis, stack<int>& st, vector<int> adj[]){
        vis[node] = 1;
        
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it, vis, st, adj);
            }
        }
        
        st.push(node);
    }
	public:
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> vis(V, 0);
	    stack<int> st;
	    
	    for(int i = 0; i < V; i++){
	        if(!vis[i]){
	            dfs(i, vis, st, adj);
	        }
	    }
	    
	    vector<int> ans;
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    
	    return ans;
	}
};


/*The problem with this solution is that if you are given a directed 
  graph that contains a cycle in the solution. The algorithm wont be 
  able to detect, it will spill out an ordering which is wrong. But 
  when using Kahn's algorithm, you will be able to detect whether topo 
  sort was possible or not. */