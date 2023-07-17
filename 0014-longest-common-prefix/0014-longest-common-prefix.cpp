class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="",temp=strs[0];
        for(int i=0;i<temp.length();i++){
            for(int j=0;j<strs.size();j++){
                if( strs[j].length() == i || strs[j][i]!=temp[i] )  return ans;
            }ans+=temp[i];
        }
        return ans;
    }
};