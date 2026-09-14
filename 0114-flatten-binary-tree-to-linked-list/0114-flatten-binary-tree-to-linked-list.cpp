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

        // 1. First flatten the left subtree
        flatten(root->left);

        // 2. Save the original right subtree
        TreeNode* right = root->right;

        // 3. Move flattened left subtree to right
        root->right = root->left;
        root->left = nullptr;

        // 4. Find the end of the flattened left subtree
        TreeNode* curr = root;

        while (curr->right != nullptr) {
            curr = curr->right;
        }

        // 5. Attach original right subtree
        curr->right = right;

        // 6. Flatten the original right subtree
        flatten(right);
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
