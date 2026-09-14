/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    unordered_map<TreeNode*, TreeNode*> parent;

    void dfs(TreeNode* root, TreeNode* par) {
        if (root == nullptr)
            return;

        parent[root] = par;

        dfs(root->left, root);
        dfs(root->right, root);
    }

    int amountOfTime(TreeNode* root, int start) {

        dfs(root, nullptr);

        TreeNode* targetNode = nullptr;

        for (auto &x : parent) {
            if (x.first->val  == start) {
                targetNode = x.first;
                break;
            }
        }

        if (targetNode == nullptr)
            return 0;

        queue<TreeNode*> q;
        unordered_map<TreeNode*, int> dist;

        q.push(targetNode);
        dist[targetNode] = 0;

        while (!q.empty()) {

            TreeNode* curr = q.front();
            q.pop();

            if (curr->left && !dist.count(curr->left)) {
                dist[curr->left] = dist[curr] + 1;
                q.push(curr->left);
            }

            if (curr->right && !dist.count(curr->right)) {
                dist[curr->right] = dist[curr] + 1;
                q.push(curr->right);
            }

            if (parent[curr] && !dist.count(parent[curr])) {
                dist[parent[curr]] = dist[curr] + 1;
                q.push(parent[curr]);
            }
        }

        int ans = 0;

        for (auto &x : dist) {
            ans = max(ans, x.second);
        }

        return ans;
    }
};