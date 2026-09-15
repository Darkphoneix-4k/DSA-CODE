
class Solution {
public:
    void recoverTree(TreeNode* root) {

        stack<TreeNode*> st;

        TreeNode* prev = nullptr;
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;

        TreeNode* curr = root;

        while (curr != nullptr || !st.empty()) {

            while (curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            }

            curr = st.top();
            st.pop();

            if (prev != nullptr && prev->val > curr->val) {

                if (first == nullptr) {
                    first = prev;
                }

                second = curr;
            }

            prev = curr;

            curr = curr->right;
        }

        swap(first->val, second->val);
    }
};