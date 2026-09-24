struct node {
    node*  child [26];
    bool isend ;

 node (){
    isend = false ;
    for (int i =0; i< 26;i++){
        child [i]= nullptr ;
    }
 }
};


class Trie {
    node* root ;
public:
    Trie() {
        root = new node();
    }
    
    void insert(string word) {
       node* curr = root ;
       for ( char ch : word){
        int index = ch - 'a';
        if (curr-> child[index]== nullptr){
            curr-> child[index]= new node();
        }
        curr = curr->child[index];
       }
       curr->isend = true; 
        
    }
    
    bool search(string word) {
        node* curr = root;
       for ( char ch : word){
        int index = ch - 'a'; 
         if (curr-> child[index]== nullptr){
            return false ;
        }
        curr= curr-> child[index];
       }return curr->isend;

    }
    
    bool startsWith(string prefix) {
        node* curr = root;
       for ( char ch : prefix){
        int index = ch - 'a'; 
         if (curr-> child[index]== nullptr){
            return false ;
        }
        curr= curr-> child[index];
       }
       return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */