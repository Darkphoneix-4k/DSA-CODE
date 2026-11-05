class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n = arr1.size();
        int m = arr2.size();
        int y = 0;
        for (int i = 0; i < n ; i++ ){
           int count = 0;
            for (int j = 0; j < m ; j++){
                int x = abs(arr1[i] - arr2[j]) ;
                if (x <= d){
                  count++;
                }
            }
            if (!count){
                y++;
            }
        }
        return y;
    }
};