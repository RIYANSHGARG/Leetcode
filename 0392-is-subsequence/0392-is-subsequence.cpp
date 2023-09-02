class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0,j=0;
        while(i<t.length() && j<s.length()){
            if(t[i]==s[j]){i++;j++;}
            else i++;
        }
        return j>=s.length();
    }
};