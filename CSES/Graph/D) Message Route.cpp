#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> adj[n+1]; 

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<int> q;
    q.push(1);
    vector<int> dist(n+1, INT_MAX);
    dist[1] = 0;
    vector<int> parent(n + 1, -1);

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto adjn : adj[node]){
            if(dist[adjn] == INT_MAX){
                dist[adjn] = 1 + dist[node];
                q.push(adjn);
                parent[adjn] = node;
            }
        }
    }
    
    if(dist[n] == INT_MAX){
        cout << "IMPOSSIBLE";
        return 0;
    }

    vector<int> path;
    int node = n;
    while(parent[node] != -1){
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(1);
    reverse(path.begin(), path.end());

    cout << dist[n] + 1<< endl;
    for(int i = 0; i < (int)path.size(); i++){
        cout << path[i] << " ";
    }

    return 0;
}