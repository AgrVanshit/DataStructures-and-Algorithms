//https://leetcode.com/problems/number-of-provinces/description/


class Solution {
private:
    void dfs(int node, vector<int> adjLs[], vector<int>& vis){
        vis[node] = 1;
        for(auto it : adjLs[node]){
            if(!vis[it]){
                dfs(it, adjLs, vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<int> vis(n+1, 0);
        vector<int> adjLs[n+1];

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isConnected[i][j] == 1 && i != j){
                    adjLs[j+1].push_back(i+1);
                    adjLs[i+1].push_back(j+1);
                }
            }
        }

        int cnt = 0;

        for(int i = 1; i < n+1; i++){
            if(vis[i] == 0){
                cnt++;
                dfs(i, adjLs, vis);
            }
        }
        
        return cnt;
    }
};