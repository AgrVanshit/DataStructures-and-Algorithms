//*****https://leetcode.com/problems/validate-binary-search-tree/description/*****


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


//T.C: O(n);
//S.C: O(n);
class Solution {
public:
    bool solve(TreeNode* root, long long left, long long right){
        if(root == NULL) return true;

        if(root -> val >= right || root -> val <= left) return false;

        bool l = solve(root -> left, left, root -> val);
        if(!l) return l;
        bool r = solve(root -> right, root -> val, right);
        if(!r) return r;

        return l && r;
    }
    bool isValidBST(TreeNode* root) {
        long long left = LONG_MIN;
        long long right = LONG_MAX;
        return solve(root, left, right);
    }
};


/*Another approach to this question could be to use inorder traversal
  and make sure it is strictly increasing. For the inorder traversal 
  we could use morris traversal so that no auxillary stack space is 
  used which in case of recursion would have been O(n). */