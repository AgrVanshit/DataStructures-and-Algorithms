//*****https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1*****


//BELLMAN FORD ALGORITHM:

/*Helps to detect shortest path even in the case of negative weights 
  and negative cycle also that Djikstra's Algorithm wouldn't. */

/*This algorithm will only work if we are given a directed graph, 
  in case of undirected graph to use this algorithm convert it into 
  directed graph by having the two side edges with the same edge weight 
  and then use this algorithm. */

/*Relax all the edges (n-1) times sequentially, relaxing an edge means
  if(dist[u] + wt < dist[v]) then dist[v] = dist[u] + wt. 
  Since, in a graph of n nodes, in worst case, you will take (n-1) edges
  to reach from the first to the last, thereby we iterate for (n-1) 
  iterations in Bellman Ford Algorithm. */
  
//T.C: O(E + V); // E -> Total no. of edges, V -> Total no. of nodes.
//S.C: O(V);
class Solution{
public:
	/*  edges: vector of vectors which represents the graph
	*   S: source vertex to start traversing graph with
	*   V: number of vertices
	*/
	vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S){
		vector<int> dist(V, 1e8);
		dist[S] = 0;

		for(int i = 0; i < V - 1; i++){
			for(auto it : edges){
				int u = it[0];
				int v = it[1];
				int wt = it[2];
				if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
					dist[v] = dist[u] + wt;
				}
			}
		}

		// Vth iteration to check negative cycle.
        /*Even after V-1 iterations the dist array is updated with any 
          shorter dist in tne Vth iteration means negative cycle is 
          present in the graph. */
		for(auto it : edges){
			int u = it[0];
			int v = it[1];
			int wt = it[2];
			if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
				return {-1};
			}
		}
        
		return dist;
	}
};