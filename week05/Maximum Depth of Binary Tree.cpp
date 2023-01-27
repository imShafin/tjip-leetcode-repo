/// TC: O(N) N is the number of Nodes
/// MC: O(H) H is the height of recursion

class Solution {
public:
    int maxDepth(TreeNode* root) {
      if(!root) return 0;
      int L = maxDepth(root -> left);
      int R = maxDepth(root -> right);
      return 1 + max(L, R);
    }
};
