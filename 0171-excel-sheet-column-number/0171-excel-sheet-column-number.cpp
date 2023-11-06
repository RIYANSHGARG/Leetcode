class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans=0;
        for(int i=0;i<columnTitle.size();i++)   ans=ans+(pow(26,columnTitle.length()-1-i)* (columnTitle[i]-'A'+1) );
        return ans;
    }
};