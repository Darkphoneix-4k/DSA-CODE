class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map <int , int> mp;
        mp[0]= 1;
        int sum =0;
        int ans  =0 ;
        for (int i =0; i < n ; i++){
            if (nums[i] % 2 != 0){
               sum++; 
            }
            int x = sum-k ;
            if(mp.count(x)){
               ans += mp[x];
            }
            mp[sum]++;
        }
        return ans ; 
    }
};