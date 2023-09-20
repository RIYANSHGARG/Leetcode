class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int count=0;
        sort(intervals.begin(),intervals.end());
        stack<pair<int,int>> s;
        s.push({intervals[0][0] , intervals[0][1]});
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0] < s.top().second && intervals[i][1] > s.top().second)  count++;
            else if(intervals[i][0] >= s.top().first && intervals[i][1] <= s.top().second){
                count++;
                s.pop();
                s.push({intervals[i][0] , intervals[i][1]});
            }
            else    s.push({intervals[i][0] , intervals[i][1]});
        }
        return count;
    }
};