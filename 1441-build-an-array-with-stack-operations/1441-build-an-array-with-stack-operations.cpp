class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int j=0;
        vector<string> ans;
        // stack<int> s;
        for(int i=1;i<=n;i++){
            if(target[j]!=i){
                ans.push_back("Push");
                ans.push_back("Pop");
            }else{
                ans.push_back("Push");
                j++;
                if(j==target.size())    break;
            }
        }
        return ans;
    }
};