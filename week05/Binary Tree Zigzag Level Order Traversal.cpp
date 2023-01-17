TC: O(N*M)       ///N is total nodes, M is maximum nodes in a level
MC: O(N)         ///N is the Total number's of Node 

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> allLevels;
        queue<TreeNode*> nodeTracker;
        nodeTracker.push(root);
        bool levelStatus = true;
        while(!nodeTracker.empty()) {
            int len = nodeTracker.size();
            vector<int> nodesInLevel;
            for(int i = 0; i < len; i++) {  
                auto parent = nodeTracker.front();
                nodeTracker.pop();
                if(parent) nodesInLevel.push_back(parent->val);
                if(parent && parent->left) nodeTracker.push(parent->left);
                if(parent && parent->right) nodeTracker.push(parent->right);
            }
            if(!levelStatus) reverse(nodesInLevel.begin(), nodesInLevel.end());
            if(nodesInLevel.size()) allLevels.push_back(nodesInLevel);
            levelStatus = !levelStatus;
        }
        return allLevels;
    }
};
