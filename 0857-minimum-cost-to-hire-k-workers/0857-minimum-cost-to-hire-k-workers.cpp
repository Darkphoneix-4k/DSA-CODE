class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double, int>> workers(n);
        for (int i = 0; i < n; ++i) {
            workers[i] = {(double)wage[i] / quality[i], quality[i]};
        }
        
        sort(workers.begin(), workers.end());
        
        double min_total_cost = 1e18;
        int quality_sum = 0;
        priority_queue<int> max_heap;
        
        for (int i = 0; i < n; ++i) {
            double current_ratio = workers[i].first;
            int current_quality = workers[i].second;
            
            max_heap.push(current_quality);
            quality_sum += current_quality;
            
            if (max_heap.size() > k) {
                quality_sum -= max_heap.top();
                max_heap.pop();
            }
            
            if (max_heap.size() == k) {
                min_total_cost = min(min_total_cost, current_ratio * quality_sum);
            }
        }
        
        return min_total_cost;
    }
};