class Solution {
public:
    vector<string> createGrid(int m, int n) {
      vector<string> v(m, string(n, '#'));
      for (int i = 0; i < m ; i++){
        v[i][0] = '.';
      }
      for (int j = 0; j < n ;j++){
        v[m-1][j] = '.';
      }
      return v ;
    }
};