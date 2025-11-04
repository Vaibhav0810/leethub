/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        // If depth is 1, create a new root and attach the current tree as the
        // left child
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root; // Attach the old root to the new root
            return newRoot;
        }

        // Initialize a queue for level-order traversal (BFS)
        queue<TreeNode*> q;
        q.push(root);
        int currentLevel = 1;

        // Perform level-order traversal
        while (!q.empty()) {
            int levelSize =
                q.size(); // Get the number of nodes at the current level

            // If we are at the level just before the desired depth
            if (currentLevel == depth - 1) {
                // Traverse all nodes at this level
                for (int i = 0; i < levelSize; ++i) {
                    TreeNode* node = q.front();
                    q.pop();

                    // Create new nodes at this level
                    TreeNode* leftChild = new TreeNode(val);
                    TreeNode* rightChild = new TreeNode(val);

                    // Attach the old children of the node to the new nodes
                    leftChild->left = node->left; // New left node's left child
                                                  // is the old left child
                    rightChild->right =
                        node->right; // New right node's right child is the old
                                     // right child

                    // Set the new nodes as left and right children of the
                    // current node
                    node->left = leftChild;
                    node->right = rightChild;
                }
                break; // Once we've inserted the row, break out of the loop
            }

            // Otherwise, add the next level nodes to the queue for the next
            // iteration
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            currentLevel++; // Move to the next level
        }

        return root; // Return the root of the modified tree
    }
};