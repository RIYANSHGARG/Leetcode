class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
        set<string> s(nums.begin(),nums.end());
        
        for(int i=0;i< (1<< (n));i++){
            string ans="";
            for(int j=0;j<n;j++){
                if(i&(1<<j)) ans+= "1";
                else ans+="0";
            }
            if(s.find(ans)==s.end()){
                return ans;
            }
        }
        return "";
    }
};