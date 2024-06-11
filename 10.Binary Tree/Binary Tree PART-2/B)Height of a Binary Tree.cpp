//*****https://leetcode.com/problems/maximum-depth-of-binary-tree/description/*****


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


//*****Using Recursion*****
//T.C: O(n);
//S.C: O(n);
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;

        int lh = maxDepth(root -> left);
        int rh = maxDepth(root -> right);

        return 1 + max(lh, rh);
    }
};


//*****Using Level Order Traversal*****
//T.C: O(n);
//S.C: O(n);
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        queue<TreeNode*> q;

        q.push(root);
        int depth = 0;

        while(!q.empty()){

            int size = q.size();

            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node -> left != NULL) q.push(node -> left);
                if(node -> right != NULL) q.push(node -> right);
            }

            depth++;
        }
        
        return depth;
    }
};