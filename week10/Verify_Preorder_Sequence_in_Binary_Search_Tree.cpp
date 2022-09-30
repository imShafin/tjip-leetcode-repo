// TC: O(NlogN)      N is the length of preorder array
// MC: O(logH)       H is the Depth of the per recursion

class Solution {
public:
  int currIdx = 0;
  void checkValidity(vector<int>& preorder, int L, int R)
  {
    if(currIdx >= preorder.size() ) return;
    int V = preorder[currIdx];
    if (V < L || V > R)
    {
      return;
    }
    currIdx++;
    checkValidity(preorder, L, V - 1);
    checkValidity(preorder, V + 1, R);
  }

  bool verifyPreorder(vector<int>& preorder) {
    int sizeOfPreorderSeq = preorder.size();
    checkValidity(preorder, INT_MIN, INT_MAX);
    return currIdx == preorder.size();
  }
};
