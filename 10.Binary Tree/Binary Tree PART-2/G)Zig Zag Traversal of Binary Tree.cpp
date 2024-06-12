//*****https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/*****


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


//*****Bruteforce from Level Order Traversal*****
//T.C: O(n) + (Additional time for reversing the each level);
//S.C: O(n);
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<TreeNode*> q;

        q.push(root);

        int cnt = 0;
        while(!q.empty()){
            int size = q.size();
            vector<int> level;

            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();

                if(node -> left != NULL) q.push(node -> left);
                if(node -> right != NULL) q.push(node -> right);

                level.push_back(node -> val);
            }

            if(cnt%2 == 0) ans.push_back(level);
            else{ 
                reverse(level.begin(), level.end());
                ans.push_back(level);
            }

            cnt++;
        }

        return ans;
    }
};


//*****Optimized Solution*****
//T.C: O(n);
//S.C: O(n);
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<TreeNode*> q;

        q.push(root);

        bool flag = true;

        while(!q.empty()){
            int size = q.size();
            vector<int> level(size);

            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();

                int ind;
                if(flag == true) ind = i;
                else ind = size - i -1;

                level[ind] = node -> val;

                if(node -> left) q.push(node -> left);
                if(node -> right) q.push(node -> right);
            }

            ans.push_back(level);
            flag = !flag;
        }

        return ans;
    }
};