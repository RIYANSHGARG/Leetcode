class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
//         NGL(nearest greater element on left index)
        
        vector<int> ans;
        stack<pair<int,int>> s;
        
        for(int i=temp.size()-1;i>=0;i--){
            while(!s.empty() && s.top().first <=temp[i]) s.pop();
            if(s.empty())   ans.push_back(0);
            else    ans.push_back(s.top().second - i);
            s.push({temp[i],i});
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};