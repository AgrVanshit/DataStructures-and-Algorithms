//*****https://leetcode.com/problems/binary-tree-right-side-view/description/*****


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


//*****Iterative Approach 1(Level order Traversal 1)*****
//T.C: O(n);
//S.C: O(n) + O(n);
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        map<int, int> mpp;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            TreeNode* node = it.first;
            int lev = it.second;
            
            mpp[lev] = node -> val;

            if(node -> left) q.push({node -> left, lev + 1});
            if(node -> right) q.push({node -> right, lev + 1});
        }
        for(auto it : mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};


//*****Iterative Approach 2(Level order Traversal 2)*****
//T.C: O(n);
//S.C: O(n);
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        int lev = 0;
        while(!q.empty()){
            int s = q.size();
            for(int i = 0; i < s; i++){
                TreeNode* node = q.front();
                q.pop();
                
                if(ans.size() == lev){
                    ans.push_back(node -> val);
                }
                
                if(node -> right) q.push(node -> right);
                if(node -> left) q.push(node -> left);
            }
            lev++;
        }
        return ans;
    }
};


//*****Recursive Approach*****
//T.C: O(n);
//S.C: O(Height of the tree);
class Solution {
public:
    void solve(TreeNode* root, int level, vector<int>& ans){
        if(root == NULL) return;

        if(ans.size() == level) ans.push_back(root -> val);

        solve(root -> right, level+1, ans);
        solve(root -> left, level+1, ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        solve(root, 0, ans);
        return ans;
    }
};