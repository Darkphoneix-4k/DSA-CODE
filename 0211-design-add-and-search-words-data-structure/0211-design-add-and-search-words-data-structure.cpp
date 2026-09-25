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
class WordDictionary {
    node* root;
public:
    WordDictionary() {
        root = new node ();
    }
    
    void addWord(string word) {
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
    bool Search(node* curr, string& word, int i)
{
    if (i == word.size())
        return curr->isend;

    if (word[i] != '.')
    {
        int index = word[i] - 'a';

        if (curr->child[index] == nullptr)
            return false;

        return Search(curr->child[index], word, i + 1);
    }

    for (int j = 0; j < 26; j++)
    {
        if (curr->child[j] != nullptr)
        {
            if (Search(curr->child[j], word, i + 1))
                return true;
        }
    }

    return false;
}
    
    bool search(string word) {
        return Search (root , word , 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */