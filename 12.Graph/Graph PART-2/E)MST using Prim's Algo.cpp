//*****https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1*****


//PRIM'S ALGORITHM:
//T.C: 2*O(E*log(E));
//S.C: O(V + E);
//Spanning tree having minimum edge weight sum is minimum spanning tree.
//This Algorithm helps us to find minimum spanning tree as well as the minimum edge weight sum.
class Solution
{
public:
    int spanningTree(int V, vector<vector<int>> adj[]){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

		vector<int> vis(V, 0);
			
		// {wt, node}
		pq.push({0, 0});
		int sum = 0;
		while(!pq.empty()){
			auto it = pq.top();
			pq.pop();
			int node = it.second;
			int wt = it.first;

			if(vis[node] == 1) continue;
		
			// add it to the sum
			vis[node] = 1;
			sum += wt;
			for(auto it : adj[node]){
				int adjNode = it[0];
				int edW = it[1];
				if(!vis[adjNode]){
					pq.push({edW, adjNode});
				}
			}
		}

		return sum;
    }
};


// Below written code finding MST also with the sum.
//T.C: 2*O(E*log(E));
//S.C: O(V + E + E);
class Solution
{
public:
    vector<pair<int, int>> spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>> pq;

		vector<int> vis(V, 0);
		vector<pair<int, int>> mst;
		// {parent, node}
			
		// {wt, {node, parent}}
		pq.push({0, {0, -1}});
		int sum = 0;
		while(!pq.empty()) {
			auto it = pq.top();
			pq.pop();
			int node = it.second.first;
			int parent = it.second.second;
			int wt = it.first;

			if (vis[node] == 1) continue;
			
			// add it to the mst
			if(parent != -1) mst.push_back({parent, node});
			vis[node] = 1;
			sum += wt;
			for(auto it : adj[node]) {
				int adjNode = it[0];
				int edW = it[1];
				if (!vis[adjNode]) {
					pq.push({edW, {adjNode, node}});
				}
			}
		}
		return mst;
    }
};
