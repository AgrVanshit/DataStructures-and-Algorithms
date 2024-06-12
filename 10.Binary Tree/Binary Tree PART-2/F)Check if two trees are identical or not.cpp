//*****https://leetcode.com/problems/same-tree/description/*****


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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) return true;
        if(p == NULL || q == NULL) return false;
        if(p->val != q->val) return false;

        bool left = isSameTree(p -> left, q -> left);
        bool right = isSameTree(p -> right, q -> right);

        return left & right;
    }
};


//*****Using Level Order Traversal*****
/*Here we need to push NULL node also in the queue 
  so that we can compare even at the NULL node that
  if on one tree we are at the NULL node than on 
  other tree also we should be present at the NULL
  node only. */
//T.C: O(n);
//S.C: O(n);
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> Q;
        if(p == NULL || q == NULL) return p==q;               //If both roots are null
        Q.push(p); Q.push(q);                                 //Push both the roots in the queue      
                    
        while(!Q.empty())  {
            TreeNode* left = Q.front(); Q.pop();              //Store one node in left and pop
            TreeNode* right = Q.front(); Q.pop();             //Store other in right and pop

            if(left == NULL && right == NULL) continue;       //If both nodes are null -> continue
            if(left == NULL || right == NULL) return false;   //If one of them is null, simply return false
            if(left->val != right->val) return false;         //If they are not equal, return false
            
            //Push left childs of both nodes
            Q.push(left->left);                         
            Q.push(right->left);

            //Push right child of both nodes
            Q.push(left->right);
            Q.push(right->right);
        }
        return true;  
    }
};