
class Solution {
public:
int n ;
TreeNode* solve (vector<int>& nums,int p ,int q){
    if (p>q){
        return nullptr;
    }
    int mid = p + (q - p )/2  ;
     TreeNode* root = new TreeNode (nums[mid]);
     root-> left = solve (nums , p , mid-1 );
     root-> right = solve (nums , mid+1 , q);
     return root;
}
    TreeNode* sortedArrayToBST(vector<int>& nums) {
       n =nums.size();
       
      return solve (nums , 0 , n-1);
    }
};