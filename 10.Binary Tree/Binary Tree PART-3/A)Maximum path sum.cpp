//*****https://leetcode.com/problems/binary-tree-maximum-path-sum/description/*****


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
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxPathDown(root, maxi);
        return maxi;
    }

    int maxPathDown(TreeNode* node, int& maxi){
        if(node == NULL) return 0;

        int leftSum = max(0, maxPathDown(node -> left, maxi));
        int rightSum = max(0, maxPathDown(node -> right, maxi));
        
        maxi = max(maxi, node->val + leftSum + rightSum);

        return node->val + max(leftSum, rightSum);
    }
};