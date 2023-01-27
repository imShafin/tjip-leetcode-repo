///TC : O(NlogN)   /// N is total node of the tree
///MC : O(D)       /// D is maximum depth of recursion.
class Solution {
public:
    bool check(TreeNode* L, TreeNode* R) {
        if (!L && !R) return true;
        if (!L || !R) return false;
        return (L->val == R->val) && check(L->left, R->right) && check(L->right, R->left);
    }    
    bool isSymmetric(TreeNode* root) 
    {
        return check(root->left, root->right);
    }
};