//*****https://leetcode.com/problems/symmetric-tree/description/*****


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
/*S.C: O(log(n)); i.e the height of the tree,
  here in case of skew tree S.C can not be O(n)
  because skew tree will return false at the first
  step of traversal, it will not traverse to all 
  the n nodes. */
class Solution {
public:
    bool solve(TreeNode* lnode, TreeNode* rnode){
        if(lnode == NULL || rnode == NULL) return lnode == rnode;

        if(lnode -> val != rnode -> val) return false;

        bool first = solve(lnode -> left, rnode -> right);
        if(!first) return first;
        bool second = solve(lnode -> right, rnode -> left);

        return first && second;
    }
    bool isSymmetric(TreeNode* root) {
        return root == NULL || solve(root -> left, root -> right);
    }
};