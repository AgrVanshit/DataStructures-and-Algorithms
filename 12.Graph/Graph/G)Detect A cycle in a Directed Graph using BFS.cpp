//*****https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1*****


//T.C: O(n + E) + O(n) + O(n) + O(E);
//S.C: 2*O(n);
class Solution {
public:
	vector<int> topo(int N, vector<int> adj[]) {
        queue<int> q; 
        vector<int> indegree(N, 0); 

	    for(int i = 0; i < N; i++) {
	        for(auto it: adj[i]) {
	            indegree[it]++; 
	        }
	    }
	    
	    for(int i = 0; i < N; i++) {
	        if(indegree[i] == 0) {
	            q.push(i); 
	        }
	    }
        
        int cnt = 0;

	    while(!q.empty()) {
	        int node = q.front(); 
	        q.pop();

            cnt++;

	        for(auto it : adj[node]) {
	            indegree[it]--;
	            if(indegree[it] == 0) {
	                q.push(it); 
	            }
	        }
	    }

        /*(cnt == N) means topo sort have all N nodes, means topo sort is 
          possible hence, graph is Directed and Acyclic. */
	    if(cnt == N) return false;
        return true;
	}
};