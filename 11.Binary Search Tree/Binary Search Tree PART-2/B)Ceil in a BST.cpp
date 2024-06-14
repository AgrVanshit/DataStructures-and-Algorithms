//*****https://www.geeksforgeeks.org/problems/implementing-ceil-in-bst/1*****


//Recursive Approach:
//T.C: O(log(n));
//S.C: O(log(n));
void help(Node* root , int target , int &ans){
    
    if(root== NULL) return;
    
    if(root->data == target){
        ans = target;
        return;
    }
    else if(root->data > target){
        ans  = root -> data;
        help(root->left , target, ans);
    }
    else{
        help(root->right, target, ans);
    }
}
int findCeil(Node* root, int input) {
    if (root == NULL) return -1;
    int ans = -1;
    help(root, input , ans);
    return ans;
}


//Iterative Approach:
//T.C: O(log(n));
//S.C: O(1);
int findCeil(Node* root, int input) {
    int ceil = -1;
    if (root == NULL) return -1;
    
    while(root != NULL){
        if(root -> data == input){
            ceil = root -> data;
            return ceil;
        }
        if(root -> data > input){
            ceil = root -> data;
            root = root -> left;
        }
        else root = root -> right;
    }

    return ceil;
}