class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> ans;
        stack<int> s;
        for(int i=arr.size()-1;i>=0;i--){
            if(s.empty()){
                s.push(arr[i]);
                ans.push_back(-1);
                continue;
            }
            ans.push_back(s.top());
            if(arr[i]>s.top()){
                s.push(arr[i]);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};