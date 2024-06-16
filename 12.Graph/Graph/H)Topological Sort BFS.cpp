//*****https://www.geeksforgeeks.org/problems/topological-sort/1*****


//T.C: O(n + E) + O(n) + O(n) + O(E);
//S.C: 3*O(n);
//****KAHN'S ALGORITHM****
/* 1) Find in degree of all nodes.
   2) Insert all the nodes with indegree 0 in the queue.
   3) Take out front element from queue, push it in the 
      topo vector, reduce indegree of nodes by 1 to which 
      it is pointing, if indegree of any node become zero 
      push it in the queue.
   4) Continue this step until the queue becomes empty, the 
      topo array we get after this is our topological order.*/
class Solution {
public:
	vector<int> topoSort(int V, vector<int> adj[]) {
        queue<int> q; 
        vector<int> indegree(V, 0); 

	    for(int i = 0; i < V; i++) {
	        for(auto it: adj[i]) {
	            indegree[it]++; 
	        }
	    }
	    
	    for(int i = 0; i < V; i++) {
	        if(indegree[i] == 0) {
	            q.push(i); 
	        }
	    }

	    vector<int> topo;

	    while(!q.empty()) {
	        int node = q.front(); 
	        q.pop(); 
	        topo.push_back(node);

	        for(auto it : adj[node]) {
	            indegree[it]--;
	            if(indegree[it] == 0) {
	                q.push(it); 
	            }
	        }
	    }

	    return topo;
	}
};


/*An element's indegree will become 0 only when all the parent 
  nodes(nodes pointing to it) are withdrawn that is put into the 
  topo list. Since every possible node (which could have that 
  element as a neighbour) is already taken out of the queue and 
  put into the topo list, so our neighbour node won't be touched 
  again. And for not touching an already touched node, visited 
  array is required, and it purpose is already solved in kahn's 
  algorithm itslef, so no vis array is required here!! */