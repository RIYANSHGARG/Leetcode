class Solution {
public:
    int lengthOfLastWord(string s) {
        reverse(s.begin(),s.end());
        stringstream ss(s);
        string ans;
        ss>>ans;
        return ans.length();
    }
};