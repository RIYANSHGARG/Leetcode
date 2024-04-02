class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        stack<pair<int,int>> st;
        
        for(int i=0;i<intervals.size();i++){
            if(st.empty())  st.push({intervals[i][0],intervals[i][1]});
            else{
                if(intervals[i][0]<=st.top().second)    st.top().second=max(st.top().second,intervals[i][1]);
                else    st.push({intervals[i][0],intervals[i][1]});
            }
        }
        vector<vector<int>> ans;
        while(!st.empty()){
            ans.push_back({st.top().first,st.top().second});
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};