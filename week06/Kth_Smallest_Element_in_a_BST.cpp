/// TC: O(NlogN) /// N is k
/// MC: O(N)

class Solution {
public:
    void generateInorder(TreeNode* root, int &k, int &kthVal)
    {
      if(!root) return;
      generateInorder(root -> left, k, kthVal);
      k--;
      if(k == 0)
      {
        kthVal = root -> val;
        return;
      }
      generateInorder(root -> right, k, kthVal);
    }
    int kthSmallest(TreeNode* root, int k) {
        int kthVal;
        generateInorder(root, k, kthVal);
        return kthVal;
    }
};
