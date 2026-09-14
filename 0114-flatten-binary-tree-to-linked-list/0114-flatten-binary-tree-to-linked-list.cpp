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
    void flatten(TreeNode* root) {
        if (root == nullptr) return;

        TreeNode* right = root->right;
        TreeNode* curr = root->left;

        // Move left subtree to right
        root->right = root->left;
        root->left = nullptr;

        // If there was a left subtree
        if (curr != nullptr) {

            // Find the last node of left subtree
            while (curr->right != nullptr) {
                curr = curr->right;
            }

            // Attach original right subtree
            curr->right = right;
        } else {
            // No left subtree, so right remains where it was
            root->right = right;
        }

        // Flatten the resulting right subtree
        flatten(root->right);
    }
};





















    // void flatten(TreeNode* root) {
    //     TreeNode* curr = root;
    //     while (curr != nullptr) {
    //         if (curr->left) {
    //             TreeNode* pred = curr->left;
    //             while (pred->right) {
    //                  pred = pred-> right;
    //             }
    //                 pred->right = curr->right;
    //                 curr->right = curr->left;
    //                 curr-> left= nullptr;
                
    //         }
    //         curr= curr-> right;
    //     }
       
    // }
