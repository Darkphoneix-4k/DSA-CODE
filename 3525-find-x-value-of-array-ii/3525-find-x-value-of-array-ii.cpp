class Solution {
public:
    struct Node {
        int prod;
        int pref[5];

        Node() {
            prod = 1;
            for (int i = 0; i < 5; i++) {
                pref[i] = 0;
            }
        }
    };

    int K;
    vector<Node> seg;

    Node mergeNode(const Node& left, const Node& right) {
        Node res;

        // Product of the complete segment
        res.prod = (left.prod * right.prod) % K;

        // Prefixes completely inside the left segment
        for (int r = 0; r < K; r++) {
            res.pref[r] += left.pref[r];
        }

        // Prefixes that contain the entire left segment
        // and then some prefix of the right segment.
        for (int r = 0; r < K; r++) {
            int newRem = (left.prod * r) % K;
            res.pref[newRem] += right.pref[r];
        }

        return res;
    }

    void build(int node, int l, int r, vector<int>& nums) {
        if (l == r) {
            int v = nums[l] % K;

            seg[node].prod = v;
            seg[node].pref[v] = 1;  // the single-element prefix

            return;
        }

        int mid = l + (r - l) / 2;

        build(node * 2, l, mid, nums);
        build(node * 2 + 1, mid + 1, r, nums);

        seg[node] = mergeNode(seg[node * 2], seg[node * 2 + 1]);
    }

    void update(int node, int l, int r, int idx, int value) {
        if (l == r) {
            value %= K;

            seg[node] = Node();

            seg[node].prod = value;
            seg[node].pref[value] = 1;

            return;
        }

        int mid = l + (r - l) / 2;

        if (idx <= mid) {
            update(node * 2, l, mid, idx, value);
        } else {
            update(node * 2 + 1, mid + 1, r, idx, value);
        }

        seg[node] = mergeNode(seg[node * 2], seg[node * 2 + 1]);
    }

    // Returns information about the range [ql, qr].
    Node query(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return seg[node];
        }

        int mid = l + (r - l) / 2;

        if (qr <= mid) {
            return query(node * 2, l, mid, ql, qr);
        }

        if (ql > mid) {
            return query(node * 2 + 1, mid + 1, r, ql, qr);
        }

        Node left = query(node * 2, l, mid, ql, qr);
        Node right = query(node * 2 + 1, mid + 1, r, ql, qr);

        return mergeNode(left, right);
    }

    vector<int> resultArray(
        vector<int>& nums,
        int k,
        vector<vector<int>>& queries
    ) {
        K = k;

        int n = nums.size();

        seg.resize(4 * n);

        build(1, 0, n - 1, nums);

        vector<int> answer;

        for (auto& q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // Persistent update
            update(1, 0, n - 1, index, value);

            // We need all non-empty prefixes of nums[start...n-1].
            Node res = query(1, 0, n - 1, start, n - 1);

            answer.push_back(res.pref[x]);
        }

        return answer;
    }
};
