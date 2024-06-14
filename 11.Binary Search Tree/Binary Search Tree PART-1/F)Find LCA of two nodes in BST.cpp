//*****https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/*****


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


//Recursive Approach:
//T.C: O(log(n));
//S.C: O(log(n));
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;

        if(root -> val > p -> val && root -> val > q -> val){
            return lowestCommonAncestor(root -> left, p, q);
        }
        else if(root -> val < p -> val && root -> val < q -> val){
            return lowestCommonAncestor(root -> right, p, q);
        }

        else return root;
    }
};


//Iterative Approach:
//T.C: O(log(n));
//S.C: O(1);
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root){
            if(root -> val > p -> val && root -> val > q -> val) root = root -> left;
            else if(root -> val < p -> val && root -> val < q -> val) root = root -> right;
            else return root;
        }
        return NULL;
    }
};


