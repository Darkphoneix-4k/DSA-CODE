/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
 unordered_map <Node* , Node* > mp ;
  void dfs (Node* node , Node* clone){


    for (Node* n : node-> neighbors ){
        if (mp.find(n) == mp.end()){
            Node* neighbor = new Node (n -> val);
            mp [n] = neighbor ;
            clone -> neighbors.push_back (neighbor);
            dfs (n , neighbor);
        }
        else {
            clone -> neighbors.push_back ( mp[n]);
        }

    }
  }
    Node* cloneGraph(Node* node) {
        if (!node){
            return nullptr;
        }
        Node* clone = new Node (node-> val);
        mp[node] = clone ;
        dfs (node , clone);

return clone ;
    }
};