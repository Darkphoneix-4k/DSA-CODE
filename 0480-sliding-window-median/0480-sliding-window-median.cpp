class Solution {
private:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;

    unordered_map<int, int> delayed;

    int leftSize = 0;
    int rightSize = 0;

    void pruneLeft() {
        while (!left.empty() && delayed[left.top()] > 0) {
            delayed[left.top()]--;
            left.pop();
        }
    }

    void pruneRight() {
        while (!right.empty() && delayed[right.top()] > 0) {
            delayed[right.top()]--;
            right.pop();
        }
    }

    void balance() {
        pruneLeft();
        pruneRight();

        if (leftSize > rightSize + 1) {
            right.push(left.top());
            left.pop();

            leftSize--;
            rightSize++;
        }
        else if (rightSize > leftSize) {
            left.push(right.top());
            right.pop();

            rightSize--;
            leftSize++;
        }

        pruneLeft();
        pruneRight();
    }

public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {

        vector<double> result;

        // First window
        for (int i = 0; i < k; i++) {

            if (left.empty() || nums[i] <= left.top()) {
                left.push(nums[i]);
                leftSize++;
            }
            else {
                right.push(nums[i]);
                rightSize++;
            }

            balance();
        }

        // Median of first window
        if (leftSize > rightSize)
            result.push_back(left.top());
        else
            result.push_back(
                (left.top() + (double)right.top()) / 2.0
            );

        // Sliding window
        for (int i = k; i < nums.size(); i++) {

            int outgoing = nums[i - k];
            int incoming = nums[i];

            // Mark outgoing element for deletion
            delayed[outgoing]++;

            // Update logical size
            if (outgoing <= left.top())
                leftSize--;
            else
                rightSize--;

            // Insert incoming element
            if (incoming <= left.top()) {
                left.push(incoming);
                leftSize++;
            }
            else {
                right.push(incoming);
                rightSize++;
            }

            balance();

            // Median
            if (leftSize > rightSize)
                result.push_back(left.top());
            else
                result.push_back(
                    (left.top() + (double)right.top()) / 2.0
                );
        }

        return result;
    }
};