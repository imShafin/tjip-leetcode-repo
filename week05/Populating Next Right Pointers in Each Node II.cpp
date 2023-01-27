
/// TC: O(N)        /// N is the total number of nodes
/// MC: O(N)        /// N is the total number of nodes 
 
class Solution {
public:
    Node* connect(Node* root) {
       if(!root) return root;
       queue<Node*> QNodes;
       QNodes.push(root);
       while(!QNodes.empty()) {
           int len = QNodes.size();
           for (int i = 0; i < len; i++) {
                auto curr = QNodes.front();
                QNodes.pop();
                if (i + 1 < len) curr->next = QNodes.front();
                if (curr->left) QNodes.push(curr->left);
                if (curr->right) QNodes.push(curr->right);
           } 
       }
       return root;
    }
};