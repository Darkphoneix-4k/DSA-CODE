class Solution {
public:
 using ll = long long;
    int numOfSubarrays(vector<int>& arr) {

    ll cnt[2] = {1, 0};

    ll sum = 0;
    ll ans = 0;

    for (int x : arr) {
        sum += x;

        int rem = ((sum % 2) + 2) % 2;

        ans +=  cnt[1 - rem];

        cnt[rem]++;
    }

    return ans % 1000000007;
}
};
