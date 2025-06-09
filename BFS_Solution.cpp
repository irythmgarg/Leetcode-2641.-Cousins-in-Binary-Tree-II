/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        unordered_map<int, int> mp;  // Maps level -> sum of node values at that level
        queue<TreeNode*> q;
        q.push(root);
        int level = 1;

        // First BFS: Calculate sum at each level
        while (!q.empty()) {
            int sum = 0;
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                TreeNode* top = q.front();
                q.pop();
                sum += top->val;
                if (top->left) q.push(top->left);
                if (top->right) q.push(top->right);
            }
            mp[level] = sum;
            level++;
        }

        // Second BFS: Update each node's children values
        q.push(root);
        level = 1;
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                TreeNode* top = q.front();
                q.pop();
                int childrenSum = 0;

                if (top->left) {
                    q.push(top->left);
                    childrenSum += top->left->val;
                }
                if (top->right) {
                    q.push(top->right);
                    childrenSum += top->right->val;
                }

                // Replace children's values with (level sum - sibling sum)
                if (top->left) top->left->val = mp[level + 1] - childrenSum;
                if (top->right) top->right->val = mp[level + 1] - childrenSum;
            }
            level++;
        }

        root->val = 0; // Set root value to 0
        return root;
    }
};
