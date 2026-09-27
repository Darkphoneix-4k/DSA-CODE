class Solution {
    struct node {
        node* child[2];
        node (){
            child[0]= child[1]= nullptr;
        }
    };
 
   node* root = new node();

public:
 void insert(int num){
    node* curr = root;
     for (int i =31 ; i >=0 ; i--){
        int x = (num >> i) & 1 ;
        if (!curr->child[x]){
           curr->child [x] = new node() ;
        }
        curr = curr->child[x];
     }
    
     }
     int getmax ( int num ){
        node* curr = root;
        int ans = 0 ;
        for (int i =31 ; i >=0 ; i--){
        int x = (num >> i) & 1 ;
        int op= 1-x;
        if (curr->child[op]){
            ans|= (1 << i);
            curr= curr-> child [op];
        }
        else {
            curr=curr-> child[x];
        }


     }
     return ans ;
     }
 

    int findMaximumXOR(vector<int>& nums) {
        for (int num :nums){
            insert (num);
        }
        int ans =  0; 
        for (int num : nums){
            ans = max( ans , getmax(num));
        }
        return ans ;
    }
};