//*****https://www.naukri.com/code360/problems/981269?topList=striver-sde-sheet-problems*****


/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/


//T.C: O(3*n);
//S.C: O(4*n);
vector<vector<int>> getTreeTraversal(TreeNode *root){
    vector<int> pre, in, post;

    if (root == NULL) {
        return {};
    }

    stack<pair<TreeNode*, int>> st;

    st.push({root, 1});

    while (!st.empty()) {
        auto it = st.top();
        st.pop();

        if(it.second == 1){
            pre.push_back(it.first->data);
            it.second++;
            st.push(it); 

            if (it.first->left != NULL) {
                st.push({it.first->left, 1});
            }
        }

        else if(it.second == 2){
            in.push_back(it.first->data);
            it.second++;
            st.push(it); 

            if (it.first->right != NULL) {
                st.push({it.first->right, 1});
            }
        }

        else{
            post.push_back(it.first->data);
        }
    }

    vector<vector<int>> result;
    result.push_back(in);
    result.push_back(pre);
    result.push_back(post);
    return result;
}