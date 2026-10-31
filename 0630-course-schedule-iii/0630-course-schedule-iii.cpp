class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort (courses.begin() , courses.end() ,[] (vector <int> &a , vector <int> &b ){
            return a[1]  < b[1] ;
        });
        priority_queue <int> pq;
       
        int duration = 0;

        for (auto &p : courses){

            if (p[0] > p[1]){
                continue ;
            }
            pq.push(p[0]);

            duration += p[0];
            
            if (duration > p[1]){
                int x = pq.top();
                pq.pop();
                duration -= x ;
            }
          
        }
      return pq.size();
    }
};