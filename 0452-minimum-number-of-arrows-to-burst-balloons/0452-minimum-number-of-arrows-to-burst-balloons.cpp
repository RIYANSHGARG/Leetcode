class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        stack<pair<int,int>> s;
        sort(points.begin(),points.end());
        s.push({points[0][0],points[0][1]});
        for(int i=1;i<points.size();i++){
            if(points[i][0] <= s.top().second && points[i][1]<=s.top().second){
                s.top().second=points[i][1];
            }else if(points[i][0] > s.top().second){
                s.push({points[i][0] , points[i][1]});
            }
        }
        return s.size();
    }
};