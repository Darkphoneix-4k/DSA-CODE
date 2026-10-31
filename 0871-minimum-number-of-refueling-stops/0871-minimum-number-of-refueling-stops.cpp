class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {

        priority_queue<int> pq;

        long long fuel = startFuel;
        int prev = 0;
        int stops = 0;

        for (auto &s : stations) {

            int pos = s[0];
            int gas = s[1];

          
            fuel -= (pos - prev);


            while (fuel < 0) {

                if (pq.empty()) {
                    return -1;
                }

                fuel += pq.top();
                pq.pop();

                stops++;
            }

            pq.push(gas);

            prev = pos;
        }

        fuel -= (target - prev);

        while (fuel < 0) {

            if (pq.empty()) {
                return -1;
            }

            fuel += pq.top();
            pq.pop();

            stops++;
        }

        return stops;
    }
};