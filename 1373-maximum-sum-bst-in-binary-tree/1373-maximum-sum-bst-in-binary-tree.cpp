/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */
// class Solution {
//     class info {
//         public:
//         bool isbst;
//         int maxi ;
//         int mini;
//         int sum;

//     };



// };



















class Solution {
public:
    struct NodeInfo {
        bool isBST;
        int mn;
        int mx;
        int sum;
    };

    int ans = 0;

    NodeInfo solve(TreeNode* root) {

        // Empty tree is a BST
        if (root == nullptr)
            return {true, INT_MAX, INT_MIN, 0};

        NodeInfo left = solve(root->left);
        NodeInfo right = solve(root->right);

        // Check if current subtree is BST
        if (left.isBST && right.isBST &&
            root->val > left.mx &&
            root->val < right.mn) {

            int currSum = left.sum + right.sum + root->val;

            ans = max(ans, currSum);

            return {
                true,
                min(root->val, left.mn),
                max(root->val, right.mx),
                currSum
            };
        }

        // Not a BST
        return {false, INT_MIN, INT_MAX, 0};
    }

    int maxSumBST(TreeNode* root) {

        solve(root);

        return ans;
    }
};