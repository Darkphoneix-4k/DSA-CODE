class Solution {
public:
    int candy(vector<int>& ratings) {
        int n =ratings.size();
        vector <int> v (n , 1);
        for (int i =1 ; i < n ; i++){
            if (ratings[i-1] < ratings [i]){
                v[i] = v[i-1] +1 ;
            }
        }
        for (int i = n-2 ; i >= 0; i--){
            if (ratings[i+1] < ratings [i]){
                int x = v[i+1] + 1 ;
                v[i] = max(v[i] ,x );
            } 
        }
        int result = accumulate (v.begin() , v.end() , 0);
        return result ;
    }
};