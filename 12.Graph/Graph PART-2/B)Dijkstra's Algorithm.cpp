//*****https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1*****


//DIJKSTRA'S ALGORITHM USING PRIORITY QUEUE:
//T.C: E * log(E);  //E -> Total no. of edges (E = V(V-1) in worst case), V -> no. of nodes.
//S.C: O(V + E);
class Solution
{
	public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<int> dist(V, INT_MAX);

        dist[S] = 0;
        pq.push({0, S});

        while(!pq.empty()){
            int node = pq.top().second; //O(Heap size)
            int dis = pq.top().first;
            pq.pop();

            for(auto it : adj[node]){
                int v = it[0];
                int w = it[1];
                if(dis + w < dist[v]){
                    dist[v] = dis + w;
    
                    pq.push({dis + w, v}); //O(Heap size)
                }
            }
        }
        
        return dist;
    }
};

/*The shortest path can also be found by just using queue instead of priority queue.
  CODE:
        class Solution
        {
            public:
            vector <int> dijkstra(int V, vector<vector<int>> adj[], int S){
                queue<int> q;

                vector<int> dist(V, INT_MAX);

                dist[S] = 0;
                q.push(S);

                while(!q.empty()){
                    int node = q.front();
                    q.pop();

                    for (auto it : adj[node]){
                        int v = it[0];
                        int w = it[1];
                        if(dist[node] + w < dist[v]){
                            dist[v] = dist[node] + w;
            
                            q.push(v);
                        }
                    }
                }
                
                return dist;
            }
        };

Ques:THEN WHAT IS THE REASON OF USING PRIORITY QUEUE IN DIJKSTRA'S ALGORITHM ?
Ans: If we use queue instead of priority queue then it is like a bruteforce where 
     we are going on all the paths, but when we use priority queue we store min dist 
     first in the dist array and when any large dist comes in future it just not 
     iterate for that as dist lesser than that is already present in the dist array.
     In this we we are reducing extra iterations by using priority queue instead of 
     queue.
*/


//DIJKSTRA'S ALGORITHM USING SET:
//T.C: E * log(V);  //E -> Total no. of edges, V -> no. of nodes.
//S.C: 2*O(V);
class Solution
{
	public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        set<pair<int,int>> st; 

        vector<int> dist(V, 1e9); 
        
        st.insert({0, S}); 

        dist[S] = 0;
        
        while(!st.empty()) {
            auto it = *(st.begin()); 
            int node = it.second; 
            int dis = it.first; 
            st.erase(it); 
            
            for(auto it : adj[node]) {
                int adjNode = it[0]; 
                int edgW = it[1]; 
                
                if(dis + edgW < dist[adjNode]) {
                    /**erase if it was visited previously at 
                      a greater cost. It is done so that some 
                      extra iterations can be reduced. */
                    if(dist[adjNode] != 1e9) 
                        st.erase({dist[adjNode], adjNode});
                    
                    dist[adjNode] = dis + edgW; 
                    st.insert({dist[adjNode], adjNode}); 
                 }
            }
        }

        return dist; 
    }
};

/*We can not extensively say that using the set data structure 
  instead of priority queue is reducing the time complexity as it 
  totally depends on the graph given to us, we are reducing some 
  iterations by using the set but on the other hand we are using 
  the erase() function in set that will take a log(n) extra time 
  complexity, so we can't say that using a set or using a priority 
  queue which one is better approach */


/*T.C is O(ElogE) for priority queue and O(ElogV) for set.

Think in this manner that for priority queue, there is no way we 
can erase duplicate or recurring nodes, so in worst case heap will 
be having V*(V-1) nodes i.e  = E . and hence "logE".

For set method, we will be erasing the node from the set first before 
inserting it with a better distance, that means even in worst case, we 
won't be having duplicate nodes. hence, at worst (hypothetically) all 
vertices can be present in the set (but no single vertex will be present 
twice). hence, maximum heap size boils down to "V', that is why  "log V".
*/


//Solve: PRINTING SHORTEST PATH USING DIJKSTRA'S ALGORITHM.
//*****https://www.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1*****

//https://leetcode.com/problems/shortest-path-in-binary-matrix/description/
//https://leetcode.com/problems/path-with-minimum-effort/description/
//https://leetcode.com/problems/cheapest-flights-within-k-stops/description/
//https://leetcode.com/problems/network-delay-time/description/
//https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/description/
//https://www.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1