//*****https://leetcode.com/problems/is-graph-bipartite/description/*****


//T.C: 3*O(n);
//S.C: O(n) + O(2 * E);
class Solution {
private:
    bool checkBipartite(int start, int n,vector<vector<int>>& graph, int color[]){
        queue<int> q;
        q.push(start);

        color[start] = 0;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it : graph[node]){
                //If adj node is not coloured than clouring it with opposite colour.
                if(color[it] == -1){
                    color[it] = !color[node];
                    q.push(it);
                }
                /*If adj node is already coloured with the same colour means graph is 
                  not bipertite hence we return false. */
                if(color[it] == color[node]){
                    return false;
                }
            }
        }

        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        int color[n];

        for(int i = 0; i < n; i++) color[i] = -1;

        for(int i = 0; i < n; i++){
            if(color[i] == -1){
                if(checkBipartite(i, n, graph, color) == false) return false;
            }
        }

        return true;
    }
};