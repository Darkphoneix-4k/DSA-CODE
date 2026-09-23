
class MedianFinder {
private:
    // Smaller half
    priority_queue<int> left;

    // Larger half
    priority_queue<int, vector<int>, greater<int>> right;

public:
    MedianFinder() {
    }

    void addNum(int num) {
        // Add to the appropriate half
        if (left.empty() || num <= left.top()) {
            left.push(num);
        } else {
            right.push(num);
        }

        // Balance the heaps
        if (left.size() > right.size() + 1) {
            right.push(left.top());
            left.pop();
        }
        else if (right.size() > left.size()) {
            left.push(right.top());
            right.pop();
        }
    }

    double findMedian() {
        if (left.size() > right.size()) {
            return left.top();
        }

        return (left.top() + right.top()) / 2.0;
    }
};