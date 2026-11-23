class Solution {
public:
    int n;
    vector<vector<int>> ans;

    void solve(vector<int> temp, vector<int>& nums,
               unordered_set<int> st) {

        if (temp.size() == n) {
            ans.push_back(temp);
            return;
        }

        for (int i = 0; i < n; i++) {

            if (st.find(i) == st.end()) {

                temp.push_back(nums[i]);
                st.insert(i);

                solve(temp, nums, st);

                temp.pop_back();
                st.erase(i);
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        ans.clear();

        vector<int> temp;
        unordered_set<int> st;

        solve(temp, nums, st);

        return ans;
    }
};